#include <iostream>
#include <vector>
using namespace std;

void findPost(vector<int> &pre, vector<int> &in, vector<int> &post, int &curr,
              int st, int en) {
  int left, right, root;

  /* Searching  for root */
  for (left = st; in[left] != pre[curr]; left++)
    ;

  /* Initializing left, root and right */
  right = en - left;
  root = left;
  left = root - st;

  /* Build left subtree order */
  if (left <= 1) {
    if (left == 1) {
      post.push_back(in[st]);
      curr++;
    }
  } else
    findPost(pre, in, post, ++curr, st, root - 1);

  /* Build right subtree order */
  if (right <= 1) {
    if (right == 1) {
      post.push_back(in[en]);
      curr++;
    }
  } else
    findPost(pre, in, post, ++curr, root + 1, en);

  /* Adding root */

  post.push_back(in[root]);
  return;
}

int main() {
  vector<int> pre, in, post;
  int tmp;
  cout << "Input Preorder : ";
  while (1) {
    cin >> tmp;
    if (tmp == 0)
      break;
    pre.push_back(tmp);
  }
  cout << "Input Inorder : ";
  while (1) {
    cin >> tmp;
    if (tmp == 0)
      break;
    in.push_back(tmp);
  }
  int st = 0;
  findPost(pre, in, post, st, 0, pre.size() - 1);
  cout << "\nPost Order : ";
  for (i : post)
    cout << i << " ";
}
