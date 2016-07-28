#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
int main()
{
    int sum;
    int n ;
    scanf("%d",&n);
    std::vector<int> set(n);
    for(int i =0; i< n; i++){
        std::cin>>set[i];
    }
    scanf("%d",&sum);
    int s,l,p;
    for(s = 0; s < n; s++){
        for(l = s+1; l < n; l++){
            for( p = l+1; p < n; p++){
                    if(sum == set[s]+set[l]+set[p])
                        break;
                    printf("%d %d %d %d\n",s,l,p,set[s]+set[l]+set[p]);
            }
        }
    }
    if(s!=n&&l!=n&&p!=n)
        printf("%d %d %d True",s+1,l+1,p+1);
    else
        printf("False");
    return 0;
}
