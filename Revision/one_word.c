#include <stdio.h>
#define IN 1
#define OUT 0

int main(){
    freopen("sample.txt","r",stdin);
    int c,state;
    int nl,nw,nc;
    nl = nw = nc = 0;
    state = OUT;
    while((c=getchar())!=EOF){
        nc++;
        if(c == '\n')
            nl++;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT){
            state = IN;
            nw++;
            putchar('\n');
        }
        if(state == IN){
            putchar(c);
        }
    }
    printf("Newlines : %d\nWords : %d\nCharacters : %d",nl,nw,nc);
    return 0;
}
