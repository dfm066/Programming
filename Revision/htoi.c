#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 1024

int gethex(char c){
    if(isdigit(c)){
        return c - '0';
    }
    else if(isalpha(c)){
        if(isupper(c))
            if(c>='A' && c<='F')
                return c-'A'+10;
        if(islower(c))
            if(c>='a' && c<= 'f')
                return c-'a'+10;

    }
}
bool isvalid(char ch){
    if(isdigit(ch))
        return true;
    else if(isalpha(ch)){
        if((ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <='f'))
            return true;
        else
            return false;
    }
    else
        return false;
}
long long htoi(char s[]){
    long long dec_val = 0;
    int len  = 0;
    int en = 0;
    int st = 0;
    int i;
    const int base = 16;
    long long val = 1;
    while(s[len++]!='\0');
    len--;
    en = len-1;
    if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        st = 2;
    for(i = en; i >= st; i--){
        if(isvalid(s[i])){
            dec_val += val * gethex(s[i]);
            val *= base;
        }
        else{
            fprintf(stderr,"Invalid hex number : %s",s);
            return -1;
        }
    }
    return dec_val;
}
int main(){
    char s[SIZE];
    long long num = 0;
    printf("Enter hexadecimal number : ");
    scanf("%s",s);
    num = htoi(s);
    if(num != -1)
        printf("Decimal Value : %lld \n",num);
    return 0;
}
