#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>

using namespace std;

void problem_85() {
    int target = 2000000;
    int delta = INT_MAX;
    int r_count;
    int c, r;

    // BRUTE FORCE
    auto count_rect = [](int column, int row) {
        return column * (column + 1) * row * (row +1) / 4;
    };
    auto update_delta = [&](int column, int row) {
        int rect_count = count_rect(column,row);
        int current_delta = abs(target-rect_count);
        if (current_delta < delta) {
            c = column;
            r = row;
            delta = current_delta;
            r_count = rect_count;
        }
    };

    // Guess the lower and upper bound
    for (int i = 10; i < 100; i++) {
        for (int j = 10; j < 100; j++) {
            update_delta(i, j);
        }
    }

    printf("Count : %d\tDelta : %d\tDimensions : %d x %d\nSolution : %d\n", r_count, delta, c, r, c*r);
    return;
}

int main() {
    problem_85();
    return 0;
}