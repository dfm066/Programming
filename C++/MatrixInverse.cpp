#include <bits/stdc++.h>
using namespace std;

inline int determinant(int *a){
    return ((a[0] * a[3]) - (a[1] * a[2]));
}
int cofactor(int *a,int i,int j,int size){
    int cofact = 0;
    int row =0;
    int col =0;
    int n_size = size - 1;
    int *mat = new int[n_size*n_size];
    for(int r = 0; r < size; r++){
        for(int c =0; c < size; c++){
            if( r != i && c != j )
                mat[n_size*row + col++] = a[size * r + j];
        }
        row ++;
    }
    if((i+j)%2==0)
        cofact = 1;
    else
        cofact = -1;
    cofact *= determinant(mat);
    return cofact;
}
int main(){
    int mat[3][3] = {{1,2,3},
                     {3,1,2},
                     {2,3,1}};
    int emat[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

        }
    }

}
