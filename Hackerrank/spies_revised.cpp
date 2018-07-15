#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <inttypes.h>

using namespace std;

// Fault flags
#define     FAULT_MASK      0x0000000f
#define     NO_FAULT        0x00000000
#define     USD_FAULT       0x00000001
#define     COL_FAULT       0x00000002
#define     DIA_FAULT       0x00000004
#define     LIN_FAULT       0x00000008

// Value flags
#define     MVAL_MASK       0x00000fff
#define     HVAL_MASK       0x0fff0000
#define     LVAL_MASK       0x0000fff0
#define     HEXB_SHIFT      4
#define     HVAL_SHIFT      4 * HEXB_SHIFT
#define     LVAL_SHIFT      1 * HEXB_SHIFT

#define GET_FAULT(flag) (flag & FAULT_MASK)
#define SET_FAULT(flag, fault) (flag) = ((flag) | FAULT_MASK) & (fault | ~ FAULT_MASK);

#define GET_HVAL(flag) ((flag) & HVAL_MASK) >> HVAL_SHIFT
#define GET_LVAL(flag) ((flag) & LVAL_MASK) >> LVAL_SHIFT
#define SET_HVAL(flag, val) (flag) = ((flag) | HVAL_MASK) & (((uint32_t)(val) & MVAL_MASK) << HVAL_SHIFT | ~HVAL_MASK)
#define SET_LVAL(flag, val) (flag) = ((flag) | LVAL_MASK) & (((uint32_t)(val) & MVAL_MASK) << LVAL_SHIFT | ~LVAL_MASK)

#define MAX 1000
uint32_t available[MAX][MAX];
uint32_t update_mat[MAX][MAX];
int32_t used[MAX];

void print_available(int N){
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++){
            printf("%5d",available[i][j]);
        }
        printf("\n");
    }
}

void print_used(int N) {
    printf("Used : \n");
    for(int i = 1; i <= N; i++){
        printf("%d ",used[i]);
    }
    printf("\n");
}

int fault_change(uint32_t *flag, uint32_t  fault, int lval, int hval=0)
{
    uint32_t clval = (uint32_t)lval, chval = (uint32_t)hval;
    uint32_t cflag = 0;
    switch(GET_FAULT(*flag))
    {
        case NO_FAULT:
        case USD_FAULT:
            cflag = 1;
            break;

        case COL_FAULT:
        case DIA_FAULT:
        case LIN_FAULT:
            if (GET_LVAL(*flag) >= lval)  cflag = 1;
            break;

        default:
            cout << "INVALID FAULT" << endl;

    }
    if (cflag) {
        SET_FAULT(*flag, fault);
        SET_LVAL(*flag, lval);
        SET_HVAL(*flag, hval);
//        printf("debug3: flag - %5d fault - %5d lval - %5d\n", *flag, fault, lval);
        return 0;
    }

    return 1;
}

// TODO: Rewrite for new logic
void update(int row, int N){
    int set_break;
    int col;
    int lval, clval;
    int fault = 0;

    for (col = 1; col <= N; col++) {
            if (GET_FAULT(available[row][col]) == USD_FAULT) continue;
            set_break = 0;
        for(int i = 1; !set_break && (i < row ); i++){
                if (col == used[i]){
                    SET_LVAL(available[row][col], i);
                    SET_FAULT(available[row][col], COL_FAULT);
                    set_break = 1;
                    continue;
                } else if ( row - i == col - used[i] ||
                            row - i == used[i] - col) {
                    SET_LVAL(available[row][col], i);
                    SET_FAULT(available[row][col], DIA_FAULT);
                    set_break = 1;
                    continue;
                }
            for(int j = i+1; !set_break &&(j < row); j++){
                if (col == used[j]){
                    SET_LVAL(available[row][col], j);
                    SET_FAULT(available[row][col], COL_FAULT);
                    set_break = 1;
                    continue;
                } else if ( row - j == col - used[j] ||
                            row - j == used[j] - col) {
                    SET_LVAL(available[row][col], j);
                    SET_FAULT(available[row][col], DIA_FAULT);
                    set_break = 1;
                    continue;
                } else if (((j - i) * (col - used[i])) ==
                           ((row - i) * (used[j] - used[i]))){
                    SET_LVAL(available[row][col], j);
                    SET_FAULT(available[row][col], LIN_FAULT);
                    set_break = 1;
                    continue;
                }
            }
        }
        if (!set_break) {
            SET_LVAL(available[row][col], 0);
            SET_FAULT(available[row][col], NO_FAULT);
        }
    }
    return;
}
// TODO: Rewrite for new logic
void revert(int srt_row, int end_row, int N){
    uint32_t    clval;
    uint32_t    lval = (uint32_t)end_row;

    for(int i = srt_row; i > end_row; i--){
        available[i][0] = 0;
        used[i] = 0;
        for(int j = 1; j <= N; j++){
            clval = GET_LVAL(available[i][j]);
//            printf("debug2 : [%5d,%5d] - %5d\n", i, j, clval);
            if (clval >= lval) {
                fault_change(&available[i][j], NO_FAULT, 0);
            }
        }
    }
//    avail[end_row][0] = 0;
    return;
}

int get_available(int row, int N){
    int res = 0;
    uint32_t rval = 0, lval;
    // Update current row
    update(row, N);
    for(int i = 1; i <= N; i++){
         if(GET_FAULT(available[row][i]) == NO_FAULT){
            SET_FAULT(available[row][i], USD_FAULT);
            SET_LVAL(available[row][i], row);
            used[row] = i;
            res = i;
            break;
        } else {
            lval = GET_LVAL(available[row][i]);
//            printf("debug1 : [%5d,%5d] - %5d\n", row, i, lval);
            if (lval > rval && lval < row) {
                rval = lval;
            }
        }
    }

    // set revert row position
    if (res != 0) {
        available[row][0] = res;
    } else if (rval != 0){
        res = (int)rval;
        res *= -1;
    } else {
//         print_used(N);
//    cout << "After updating " << row << endl;
//    print_available(N);
//    getchar();
        res = 1 - row;
    }
//    if (used[1] ){
//    print_used(N);
//    cout << "After updating " << row << endl;
//    print_available(N);
//    cout << "Res : " << res << endl;
//    getchar();
//    }
    return res;
}

int main() {

	int in;
	int counter = 0;
	int pos;
	cout << "Hello HackerRank" << endl;
	cout << "Enter value of N : ";
	cin >> in;

    // Init
	for(int i = 0; i <= in; i++)
        for(int j =0; j <= in; j++)
            available[i][j] = 0;

    // Logic
    for(int i = 1; i <= in && i > 0; i++, counter++){
        if((pos = get_available(i, in)) <= 0){
            pos *= -1;
            revert(i, pos, in);
            i = pos - 1;
            continue;
        }
    }
    cout << "Found for " << in << " : " << endl;
    print_used(in);
    cout << "After updating " << in << endl;
    print_available(in);
    for(int i = 1; i <= in; i++) {
        for(int j = 1; j <= in; j++){
            if (used[i] == j)   cout << "S ";
            else    cout << "* ";
        }
        cout << endl;
    }
    cout << "total tries : " << counter << endl;
	return 0;
}
