#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;

struct LFUCacheNode {
  int key;
  int val;
  unsigned long long hotness;
  int freq;
  LFUCacheNode() : key(0), val(-1), hotness(0), freq(0) {}
  LFUCacheNode(int key, int val, unsigned long long hotness, int freq)
      : key(key), val(val), hotness(hotness), freq(freq) {}
  bool operator==(const int &other) {
      return this->key == other;
  }
};
struct LFUCacheNodeCmp {
    bool operator()(const LFUCacheNode &lhs, const LFUCacheNode &rhs) const {
      return lhs.freq < rhs.freq
                 ? true
                 : lhs.freq > rhs.freq
                       ? false
                       : lhs.hotness < rhs.hotness;
    }
};

class LFUCache {
private:
  unsigned long long _gen_no;
  size_t _capacity;
  size_t _size;
  vector<LFUCacheNode> _cache;

public:
  LFUCache(int capacity) : _capacity(capacity), _size(0), _gen_no(0) {}
  
  int get(int key) {
    ++_gen_no;
    const auto &node = find(_cache.begin(), _cache.end(), key);
    if (node == _cache.end())
      return -1;
    else {
      node->freq++;
      node->hotness = _gen_no;
      return node->val;
    }
  }

  void put(int key, int value) {
    if (_capacity == 0) return;
    ++_gen_no;
    auto node = find(_cache.begin(), _cache.end(), key);
    if (node == _cache.end()) {
        if (_size < _capacity) {
            _cache.push_back({key, value, _gen_no, 1});
            _size++;
            return;
        }
        node = min_element(_cache.begin(), _cache.end(), LFUCacheNodeCmp());
        node->key = key;
        node->freq = 0;
    }
    node->val = value;
    node->freq++;
    node->hotness = _gen_no;
    return;
  }
};

int main() {
  //     ["LFUCache","put","put","get","get","get","put","put","get","get","get","get"]
  //     [[3],[2,2],[1,1],[2],[1],[2],[3,3],[4,4],[3],[2],[1],[4]]
  LFUCache cache(3);
  cache.put(2, 2);
  cache.put(1, 1);
  cout << cache.get(1) << endl;
  cout << cache.get(2) << endl;
  cache.put(3, 3);
  cache.put(4, 4);
  cout << cache.get(3) << endl;
  cout << cache.get(2) << endl;
  cout << cache.get(1) << endl;
  cout << cache.get(4) << endl;

  return 0;
}