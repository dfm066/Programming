#include "utils.h"

double fdigits(const Point &x) { return log10(x.first) * x.second; }

int ndigits(const Point &x) { return ceil(fdigits(x)); }

bool is_max(const Point &x, const Point &y) {
  if (fdigits(y) < fdigits(x))
    return false;
  return true;
}

int main() {
 
  auto st = chrono::steady_clock::now();
  std::ifstream input(
      "G:\\Programms\\Programming\\Project Euler\\C++\\p099_base_exp.txt");
  if (!input.is_open()) {
    printf("Failed to open the file.\n");
  }
  
  string line;
  vector<Point> v;
  while (getline(input, line)) {
    const char *str = line.c_str();
    int base, exp;

    sscanf(str, "%d,%d", &base, &exp);
    v.push_back(make_pair(base, exp));
  }
  input.close();
  
  auto val = max_element(v.begin(), v.end(), is_max);
  // auto val =
  //     max_element(v.begin(), v.end(), [](const Point &x, const Point &y) {
  //       if (fdigits(y) < fdigits(x))
  //         return false;
  //       return true;
  //     });
  int lineno = (val - v.begin()) + 1;
  auto en = chrono::steady_clock::now();

  printf("\nLarget integral value : %d - %d\n", val->first, val->second);
  printf("Lineno: %d\n", lineno);
  
  

  time_diff exec_t = en-st;
  cout << "Time to execute : " << ms(exec_t).count() << "ms\t" 
       << us(exec_t).count() << "us\t" << ns(exec_t).count() << "ns\n" <<  endl;
  return 0;
}