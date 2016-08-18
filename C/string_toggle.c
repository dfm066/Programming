#include <stdio.h>

int main()
{
    char S[101],c;
    int i;
    scanf("%s",&S);
    while(!(c=S[i++])==0){
    	if(c>='a'&&c<='z'){
    		S[i-1] -= 32;
    	}
    	else if(c>='A'&&c<='Z'){
    		S[i-1] += 32;
    	}

    }
    printf("%s",S);
    return 0;
}
