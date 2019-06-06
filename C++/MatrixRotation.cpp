#include <iostream>
#include <vector>
using namespace std;

void print_matrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (const auto &col: row) {
            cout << col << " ";
        }
    }
    cout << endl;
}

void rotate_matrix(vector<vector<int>> &matrix, int N) {
    for (int width = N, start_row = 0, end_col = N-1;  width > 1; width -= 2, start_row++, end_col--) {
        for (int start_col = start_row; start_col < end_col; start_col++) {
            int curr_col = start_col, curr_row = start_row;
            int next_col = N-curr_row-1, next_row = curr_col;
            while (next_col != start_col || next_row != start_row) {
                matrix[start_row][start_col] = matrix[start_row][start_col] ^ matrix[next_row][next_col];
                matrix[next_row][next_col] = matrix[start_row][start_col] ^ matrix[next_row][next_col];
                matrix[start_row][start_col] = matrix[start_row][start_col] ^ matrix[next_row][next_col];
                curr_col = next_col;
                curr_row = next_row;
                next_col = N-curr_row-1;
                next_row = curr_col;
            }
         }
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<vector<int>> matrix(N);
        for (int i = 0; i < N; i++) {
            matrix[i] = vector<int>(N);
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }
        rotate_matrix(matrix, N);
        print_matrix(matrix);
    }
}