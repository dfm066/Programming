#include "utils.h"

using namespace std;

const int sz = 9;
const int space = sz*sz;

bool col_map[sz][sz];
bool row_map[sz][sz];
bool block_map[sz][sz];

long long counter = 0;
char header_str[128];

void reset_maps() {
    for (int y = 0; y < sz; y++) {
         for (int x = 0; x < sz; x++) {
             block_map[y][x] = true;
         }
     }
     for (int y = 0; y < sz; y++) {
         for (int x = 0; x < sz; x++) {
             col_map[y][x] = true;
         }
     }
     for (int y = 0; y < sz; y++) {
         for (int x = 0; x < sz; x++) {
             row_map[y][x] = true;
         }
     }
}

void update_maps(int x, int y, int val) {
    col_map[x][val-1] = false;
    row_map[y][val-1] = false;
    int block_idx = 3*(y/3) + (x/3);
    block_map[block_idx][val-1] = false;
}

void clear_maps(int x, int y, int val) {
    col_map[x][val-1] = true;
    row_map[y][val-1] = true;
    int block_idx = 3*(y/3) + (x/3);
    block_map[block_idx][val-1] = true;
}

void print(int sudoku[sz][sz], const char *msg) {
    cout << msg;
    for (int y = 0; y < sz; y++) {
        cout << sudoku[y][0];
        for (int x = 1; x < sz; x++) {
            cout << ", " << sudoku[y][x];
        }
        cout << "\t" << col_map[y][0];
        for (int x = 1; x < sz; x++) {
            cout << ", " << col_map[y][x];
        }

        cout << "\t" << row_map[y][0];
        for (int x = 1; x < sz; x++) {
            cout << ", " << row_map[y][x];
        }

        cout << "\t" << block_map[y][0];
        for (int x = 1; x < sz; x++) {
            cout << ", " << block_map[y][x];
        }
        cout << endl;
    }
}

bool check() {
    int block_idx = 0, idx_y, idx_x;
    for (int y = 0; y < sz; y++) {
         for (int x = 0; x < sz; x++) {
             if (block_map[y][x]) return false;
         }
     }
     for (int y = 0; y < sz; y++) {
         for (int x = 0; x < sz; x++) {
             if (col_map[y][x])  return false;
         }
     }
     for (int y = 0; y < sz; y++) {
         for (int x = 0; x < sz; x++) {
             if (row_map[y][x]) return false;
         }
     }
     return true;
}

bool is_available(int sudoku[sz][sz], int x, int y, int val) {
    int block_idx = 3*(y/3) + (x/3);
    if (col_map[x][val-1] && row_map[y][val-1] && block_map[block_idx][val-1])  return true;
    return false;
}

bool solve(int sudoku[sz][sz], int x, int y) {
    if (y == sz) {
        if (check())  return true;
        else return false;
    } else {
        if (sudoku[y][x]) {
            if (x == sz-1) {
                if (solve(sudoku, 0, y+1)) return true;
            } else {
                if (solve(sudoku, x+1, y)) return true;
            }
            return false;
        }
        for (int i = 1; i <= sz; i++) {
            if (!is_available(sudoku, x, y, i)) {
                continue;
            } 
            sudoku[y][x] = i;
            update_maps(x, y, i);

            // sprintf(header_str, "solution step : %lld\n", ++counter);
            // print(sudoku, header_str);

            if (x == sz-1) {
                if (solve(sudoku, 0, y+1)) return true;
                else {
                    sudoku[y][x] = 0;
                    clear_maps(x, y, i);
                }
            } else {
                if (solve(sudoku, x+1, y)) return true;
                else {
                    sudoku[y][x] = 0;
                    clear_maps(x, y, i);
                }
            }
        }
        return false;
    }
}



int main() {
    int sudoku[sz][sz];

    int sum = 0;
    int row = 0;
    char line[sz+2], grid[sz+2];
    
    while(!cin.eof()) {
        cin.getline(grid, sz+1);
        reset_maps();
        counter = 0;
        for (row = 0; row < sz && !cin.eof(); row++){
            cin.getline(line, sz+1);
            for (int col = 0; col < sz; col++) {
                sudoku[row][col] = line[col] - '0';
                if (sudoku[row][col])   update_maps(col, row, sudoku[row][col]);
            }
        }
        // print(sudoku, "Before solve : \n");
        if (solve(sudoku, 0, 0)) {
            // cout << "Solved " << grid << " !!" << endl;
            sum += sudoku[0][0]*100 + sudoku[0][1]*10 + sudoku[0][2];
            // print(sudoku, "After solve : \n");
        } else {
            // cout << "Couldn't solve " << grid << " !!" << endl;
            assert(0);
        }
        
    }

    cout << "Total : " << sum << endl;
}