#include <stdio.h>
int main(){
    freopen("sample.txt","r",stdin);
    int c;
    printf("\n Value getchar() != EOF : %d\n",getchar()!=EOF);
    while((c=getchar())!=EOF)
        putchar(c);
    printf("\n Value of EOF : %d",EOF);

    return 0;
}
