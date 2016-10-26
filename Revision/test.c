#include<stdio.h>
#include<stdlib.h>
int main(){
//    unsigned int a = 1;
//    int const *p = &a;
//    const int b = 10;
//    a <<= 31;
//    a -= 1;
//    printf("%d",a);
//    printf("\n%d",*p);
//    b += 31;
//    p = &b;
//    printf("\n%d",b);
//    printf("\n%d",*p);
    //char s[ ] = "Man";
    static int i = 5;
    printf("%d",i--);
    if(i)
        main();
    return 0;
}



