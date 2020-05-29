#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class BIT
{
    public:
    BIT(const vector<int> &arr) {
        m_arr.resize(arr.size() + 1, 0);
        int idx = 0;
        for(const auto &val : arr) {
            update(idx, val);
            ++idx;
        }
    }
    
    void update(int idx, int val) {
        ++idx;
        while (idx < (int)m_arr.size()) {
            m_arr[idx] += val;
            idx += idx & (-idx);
        }
    }
    
    int edge_sum(int end) const {
        int sum = 0;
        ++end;
        assert(end < (int)m_arr.size());
        while(end > 0) {
            sum += m_arr[end];
            end -= end & (-end);
        }
        return sum;
    }
    
    int interval_sum(int start, int end) const {
        return edge_sum(end) - edge_sum(start-1);
    }
    friend ostream& operator<<(ostream& out, const BIT &tree);
    private:
    vector<int> m_arr;
};

struct vblock {
    int st;
    int en;
    int val;
    friend ostream& operator<<(ostream& out, const vblock &b);
};

ostream& operator<<(ostream& out, const BIT &tree) {
    out << "[";
    for (const auto& v : tree.m_arr){
        out << v << ", ";
    }
    out << "]";
    return out;
}

ostream& operator<<(ostream& out, const vblock &b) {
    out << "[" << b.st << ", " << b.en << "] => " << b.val;
    return out;
}

void update_block(const BIT &tree, vblock &b) {
    b.val = tree.interval_sum(b.st, b.en);    
}

int solution(int K, int M, vector<int> &A) {
    if (K >= (int)A.size())
     return *min_element(A.begin(), A.end());
    if (K == 1)
        return accumulate(A.begin(), A.end(), 0);
    BIT tree(A);
    // cout << "Debug : " << tree << endl;
    vector<vblock> blocks;
    int block_size = (int)A.size() / K;
    int correct = (int)A.size() % K;
    for (int i = 0; i < K - correct; i++) {
        blocks.push_back({i*block_size, (i+1)*block_size - 1,
            tree.interval_sum(i*block_size, (i+1)*block_size - 1)
        });
    }
    
    for (int i = K - correct, st = (K - correct)*block_size; i < K; i++, st += block_size + 1) {
        blocks.push_back({st, st + block_size,
            tree.interval_sum(st, st + block_size)
        });
    }
    cout << "Debug : { ";
    for(const auto &block : blocks) {
        cout << block <<", ";
    }
    cout << "}" << endl;
    
    return min_element(blocks.begin(), blocks.end(), [&](const vblock &a, vblock &b) {
                return a.val > b.val;       
            })->val;
}
