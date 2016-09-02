<<<<<<< HEAD
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
=======
#include<stdio.h>
#include<math.h>
int main()
{
    int i;
    for(i=1;i<30;i++)
        printf("\n%d : %lld",i,(long long)pow(2.0,i));
    return 0;
}
>>>>>>> origin/master
