#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void tokenize(const string &str, vector<string> &tokens,
              const string &delimiters = " ") {
  // Skip delimiters at beginning.
  string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  // Find first "non-delimiter".
  string::size_type pos = str.find_first_of(delimiters, lastPos);

  while (string::npos != pos || string::npos != lastPos) {
    // Found a token, add it to the vector.
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    // Skip delimiters.  Note the "not_of"
    lastPos = str.find_first_not_of(delimiters, pos);
    // Find next "non-delimiter"
    pos = str.find_first_of(delimiters, lastPos);
  }
}
void print_mat(vector<vector<int>> &mat) {
  cout << "Matrix : " << endl;
  for (auto i : mat) {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }
}

int find_three_way_pathsum(vector<vector<int>> mat) {
  int m = mat.size()-1;
  int n = mat[0].size();
  int path_sum = INT_MAX;
  using point = pair<int, int>;

  for (int i = 0; i < m; i++) {
    point pos(i, 0);
    vector<int> gval(m * n, INT_MAX);
    vector<bool> visited(m * n, false);
    vector<int> path(m * n, 0);
    auto reduce_point = [&](point p) { return p.first * n + p.second; };
    auto hn = [&](point p) { return n - p.second; };
    auto fn = [&](point left, point right) {
      return (gval[reduce_point(left)] + hn(left)) >
             (gval[reduce_point(right)] + hn(right));
    };
    auto expand = [&](point p) {
      vector<point> next_pos;
      if (p.second + 1 < n) {
        point p1(p.first, p.second + 1);
        if (!visited[reduce_point(p1)])
          next_pos.push_back(p1);
      }
      if (p.first + 1 < m) {
        point p2(p.first + 1, p.second);
        if (!visited[reduce_point(p2)])
          next_pos.push_back(p2);
      }
      if (p.first - 1 >= 0) {
        point p3(p.first - 1, p.second);
        if (!visited[reduce_point(p3)])
          next_pos.push_back(p3);
      }
      return next_pos;
    };
    priority_queue<point, vector<point>, decltype(fn)> frontier(fn);
    frontier.push(pos);
    gval[reduce_point(pos)] = mat[pos.first][pos.second];
    visited[reduce_point(pos)] = true;
    while (!frontier.empty()) {
      point curr_pos = frontier.top();
      frontier.pop();
      visited[reduce_point(curr_pos)] = true;
      if (curr_pos.second == n - 1) {
        pos = curr_pos;
        break;
      }
      for (point p : expand(curr_pos)) {
        if (gval[reduce_point(p)] == 0 ||
            gval[reduce_point(p)] >
                gval[reduce_point(curr_pos)] + mat[p.first][p.second]) {
          gval[reduce_point(p)] =
              gval[reduce_point(curr_pos)] + mat[p.first][p.second];
          frontier.push(p);
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      path_sum = min(gval[i * n + n - 1], path_sum);
    }
  }
  return path_sum;
}

int main() {
  ifstream in;
  string line;
  vector<vector<int>> mat;
  vector<int> row;
  int sum = 0;
  vector<string> num;
  cout << "Enter filename : ";
  cin >> line;
  in.open(line);
  while (!in.eof()) {
    getline(in, line);
    tokenize(line, num, ",");
    for (auto i : num)
      row.push_back(stoi(i));
    mat.push_back(row);
    row.clear();
    num.clear();
  }

  sum = find_three_way_pathsum(mat);
  cout << "Minimal Path sum : " << sum << endl;

  return 0;
}
