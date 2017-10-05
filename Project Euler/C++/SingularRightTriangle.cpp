#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1500000;
const int MAXL = MAX + 1;
const int LIMIT = MAX / 2;
const int PRIM = MAX * 0.8;
const int UAD[3][3][3] = {{{1, 2, 2}, {-2, -1, -2}, {2, 2, 3}},
                          {{1, 2, 2}, {2, 1, 2}, {2, 2, 3}},
                          {{-1, -2, -2}, {2, 1, 2}, {2, 2, 3}}};
int p[MAXL];
int maxp[MAXL];

struct r_trig {
  int a;
  int b;
  int c;
  r_trig() {}
  r_trig(int a, int b, int c) : a(a), b(b), c(c) {}
  r_trig(const r_trig &x) : a(x.a), b(x.b), c(x.c) {}
  r_trig(const r_trig &&x) noexcept
      : a(move(x.a)), b(move(x.b)), c(move(x.c)) {}
  r_trig &operator=(const r_trig &x) {
    a = x.a;
    b = x.b;
    c = x.c;
    return *this;
  }

  r_trig &operator=(r_trig &&x) { return *this; }

  friend ostream &operator<<(ostream &output, const r_trig &x) {
    output << "a : " << x.a << " b : " << x.b << " c : " << x.c;
    return output;
  }
};
r_trig f(r_trig a) { return a; }

int triples[PRIM + 1][3];

int main() {
  int curr_a, curr_b, curr_c;
  int flg = 0;
  int limit = MAX / 2;
  int cnt = 0;
  queue<r_trig> q;
  r_trig curr_triple;
  triples[0][0] = 3;
  triples[0][1] = 4;
  triples[0][2] = 5;
  q.emplace(3, 4, 5);
  ++cnt;
  while (!q.empty()) {
    int tmp[3];
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      curr_triple = q.front();
      q.pop();
      for (int j = 0; j < 3; ++j) {
        tmp[0] = tmp[1] = tmp[2] = 0;
        for (int k = 0; k < 3; ++k) {
          tmp[k] += curr_triple.a * UAD[j][0][k];
          tmp[k] += curr_triple.b * UAD[j][1][k];
          tmp[k] += curr_triple.c * UAD[j][2][k];
        }
        if (tmp[2] < LIMIT) {
          q.emplace(tmp[0], tmp[1], tmp[2]);
          triples[cnt][0] = tmp[0];
          triples[cnt][1] = tmp[1];
          triples[cnt][2] = tmp[2];
          cnt += 1;
        } else {
          ++flg;
        }
      }
      // cout << curr_triple << endl;
    }
  }
  cout << "finished : " << cnt << " Flag : " << flg << endl;
  for (int i = 0; i < cnt; ++i) {
    int sum = triples[i][0] + triples[i][1] + triples[i][2];
    int mult = 1;
    int perimeter = sum * mult;
    while (perimeter > 0 && perimeter < MAXL) {
      ++p[perimeter];
      mult += 1;
      perimeter = sum * mult;
    }
  }
  int curr_cnt, curr_p, ignore;
  curr_cnt = curr_p = 0;
  for (int i = 12; i < MAXL; i += 2) {
    if (p[i] == 1) {
      curr_cnt++;
    }
  }
  cout << "Total singular triangles : " << curr_cnt << endl;
  return 0;
}
