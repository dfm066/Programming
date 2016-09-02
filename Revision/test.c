#include<stdio.h>

int main ( ) {
    static int i =34;
    char *s[]= {"balmwinter is","coming","novic"};
    char **p;
    p = s;
    *p++;i--;
    printf("%s\n",*p);
    ++*p;++i;
    printf("%s\n",*p);
    ++*p;i = 4 << i;
    printf("%s\n",*p);
    i--;
    printf("%s %d\n",++*p,--i);
}
