#include <iostream>
#include <vector>

#include "Library\C++\instrumented.h"
#include "Library\C++\table_util.h"

using namespace std;

using point = pair<int, int>;
point MOVE[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<instrumented<point>> emptypath;

vector<instrumented<point>> jump_gen(const int& n, const int& m, const int posn,
                       const int posm, const int& allowedJump,
                       const vector<vector<int>>& buildings,
                       vector<vector<bool>>& visited) {
  vector<instrumented<point>> jumps;
  for (int i = 0; i < 4; ++i) {
    int dyn = posn + MOVE[i].first;
    int dxm = posm + MOVE[i].second;
    if (dyn > n || dyn < 1 || dxm > m || dxm < 1) continue;
    int height = buildings[posn][posm] - buildings[dyn][dxm];
    if (!visited[dyn][dxm] && height >= 0 && height <= allowedJump)
      jumps.emplace_back(dyn, dxm);
  }
  return jumps;
}

pair<bool, vector<instrumented<point>>> solve(const int& n, const int& m, const int posn,
                                const int posm, const int& allowedJump,
                                const vector<vector<int>>& buildings,
                                vector<vector<bool>>& visited) {
  if ((posm <= m && posm > 0 && (posn == n || posn == 1)) ||
      (posn <= n && posn > 0 && (posm == m || posm == 1))) {
    return {true, {{posn, posm}}};
  } else if (posn > n || posn < 1 || posm > m || posm < 1) {
    return {false, move(emptypath)};
  }
  vector<instrumented<point>> nextJumps =
      jump_gen(n, m, posn, posm, allowedJump, buildings, visited);
  for (const auto jump : nextJumps) {
    visited[jump.value.first][jump.value.second] = true;
    auto validJump =
        solve(n, m, jump.value.first, jump.value.second, allowedJump, buildings, visited);
    if (validJump.first) {
      auto path = validJump.second;
      path.emplace_back(posn, posm);
      return {true, move(path)};
    }
    visited[jump.value.first][jump.value.second] = false;
  }
  return {false, move(emptypath)};
}

int main() {
  int n, m, dx, dy, j;
  cin >> n >> m;
  vector<vector<int>> buildings(n + 1);
  vector<vector<bool>> visited(n + 1);

  buildings[0] = {};
  for (int i = 1; i <= n; ++i) {
    vector<int> row(m + 1);
    vector<bool> rowVisit(m + 1);
    rowVisit[0] = false;
    for (int k = 1; k <= m; ++k) {
      cin >> row[k];
      rowVisit[k] = false;
    }
    buildings[i] = row;
    visited[i] = rowVisit;
  }
  cin >> dx >> dy >> j;

  instrumented<point>::initialize(n * m);
  auto solution = solve(n, m, dx, dy, j, buildings, visited);

  if (solution.first) {
    cout << "YES\n";
    auto path = solution.second;
    cout << path.size() << "\n";
    for (auto building = path.crbegin(); building != path.crend(); ++building) {
      cout << building->value.first << " " << building->value.second << "\n";
    }
    cout << flush;
  } else {
    cout << "NO" << endl;
  }

  size_t cols = instrumented<point>::number_ops;
  size_t decimals[cols];
  size_t normalized(0);
  *decimals = 0;
  std::fill(decimals + 1, decimals + cols, normalized);
  table_util table;
  table.print_headers(instrumented<point>::counter_names,
                      instrumented<point>::number_ops, 5);
  double* count_p = instrumented<point>::counts;
  table.print_row(count_p, decimals);
  return 0;
}