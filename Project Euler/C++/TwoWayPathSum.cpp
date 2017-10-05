#include <fstream>
#include <iostream>
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

int find_two_way_pathsum(vector<vector<int>> mat) {
  auto m = mat.size() - 1;
  auto n = mat[0].size();
  cout << "M: " << m << " N: " << n << endl;
  for (auto i = 1; i < m; ++i) {
    mat[0][i] += mat[0][i - 1];
    mat[i][0] += mat[i - 1][0];
  }
  for (auto i = 1; i < m; ++i) {
    for (auto j = 1; j < n; ++j) {
      if (mat[i][j - 1] < mat[i - 1][j])
	        mat[i][j] += mat[i][j - 1];
      else
	        mat[i][j] += mat[i - 1][j];
    }
  }
  return mat[m - 1][n - 1];
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

  sum = find_two_way_pathsum(mat);
  cout << "Maximum Path sum : " << sum << endl;

  return 0;
}
