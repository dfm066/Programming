#include<cstdio>
#include<vector>
#include<iostream>

int main(){
    std::vector<std::vector<char>> map;
    std::vector<char> row;
    int exp,M,N;
    int loc[3][3];
    char tmp;
    scanf("%d%d",&M,&N);
    exp = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            std::cin>>tmp;
            row.push_back(tmp);
            if(tmp=='s'){
                loc[exp][0]=i;
                loc[exp][1]=j;
                exp++;
            }
            if(tmp=='d'){
                dest[0][0]=i;
                dest[0][1]=j;
            }
        }
        map.push_back(row);
        row.clear();
    }
//    for(int i = 0; i < M; i++){
//        for(int j = 0; j < N; j++){
//            printf("%c ",map[i][j]);
//        }
//        printf("\n");
//    }
    for(int i =0; i < exp; i++){
        printf("%d exp loc : %d %d",i+1,loc[i][0],loc[i][1]);
    }
    printf(""
    getchar();
    return 0;
}
