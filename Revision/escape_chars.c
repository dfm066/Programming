#include <stdio.h>
#include <string.h>
int main(){
    char ch[3];
    for(int i =1; i < 255; i++){
        if(i%5==0)
            printf("\n");
        sprintf(ch,"\%c",i);
        printf("\\%c : %s \t",i,ch);
    }
    return 0;
}
