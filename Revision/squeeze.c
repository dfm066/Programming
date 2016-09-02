#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void squeeze(char s1[],char s2[]){
    int i,j,k;
    bool flg;
    for(i = 0,k=0; s1[i] != '\0'; i++){
        flg = false;
        for(j = 0; s2[j] !='\0'; j++){
            if(s1[i] == s2[j])
                flg = true;
        }
        if(!flg)
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
    return 0;
}

int main(){
    char s1[1024];
    char s2[1024];
    printf("\nEnter 2 strings : ");
    scanf("%s %s",s1,s2);
    printf("\nBefore squeeze : %20s %20s",s1,s2);
    squeeze(s1,s2);
    printf("\nAfter squeeze :  %20s %20s",s1,s2);
    return 0;
}
