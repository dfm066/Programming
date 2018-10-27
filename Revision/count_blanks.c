#include <stdio.h>
int main(){
    freopen("sample.txt","r",stdin);
    int c;
    int blanks,tabs,newlines;
    blanks = 0;
    tabs = 0;
    newlines = 0;
    while((c=getchar())!=EOF){
        if(c == ' ')
            blanks++;
        else if(c == '\t')
            tabs++;
        else if(c == '\n')
            newlines++;
    }
    printf("Blanks : %d\nTabs : %d\nNewlines : %d",blanks,tabs,newlines);
    return 0;
}
