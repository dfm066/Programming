#include <stdio.h>
typedef struct{
    char c1;
    int num;
    char c2;
}a;

typedef struct{
    char c1;
    char c2;
    int num;
}b;

int main(){
    a x;
    b y;
    printf("%d %d %d",sizeof(x),sizeof(y));
    return 0;
}
