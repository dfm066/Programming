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
                    if(sum == set[s]+set[l]+set[p]){
//                        printf("%d %d %d",s+1,l+1,p+1);
                        printf("True");
                        return 0;
                    }
            }

        }
    }
    printf("False");
    return 0;
}
