<<<<<<< HEAD
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
using namespace std;
int digit[10];
int num[10];
int main(){
    int T,tmp;
    int N,f;
    scanf("%d",&T);
    while(T--){
        memset(digit,0,sizeof(digit));
        memset(num,0,sizeof(num));
        scanf("%d",&N);
        fori(i,N){
            scanf("%d",&tmp);
            digit[9-tmp]++;
        }
        if(digit[9]==0){
            cout<<-1<<endl;
        }
        else{
            fori(i,10){
                if(i%3==0)
                    num[i] = digit[i];
                else if(i == 1&& digit[i]){
                    num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                    if(digit[i+1]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+1]?digit[i+1]:digit[i];
                        num[i] += tmp;
                        num[i+1] += tmp;
                        digit[i] -= tmp;
                        digit[i+1] -= tmp;
                    }
                    if(digit[i+4]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+4]?digit[i+4]:digit[i];
                        num[i] += tmp;
                        num[i+4] += tmp;
                        digit[i] -= tmp;
                        digit[i+4] -= tmp;

                    }
                    if(digit[i+7]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+7]?digit[i+7]:digit[i];
                        num[i] += tmp;
                        num[i+7] += tmp;
                        digit[i] -= tmp;
                        digit[i+7] -= tmp;
                    }

                }
                else if(i==2&& digit[i]){
                        num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                     if(digit[i+2]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+2]?digit[i+2]:digit[i];
                        num[i] += tmp;
                        num[i+2] += tmp;
                        digit[i] -= tmp;
                        digit[i+2] -= tmp;
                    }
                    if(digit[i+5]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+5]?digit[i+5]:digit[i];
                        num[i] += tmp;
                        num[i+5] += tmp;
                        digit[i] -= tmp;
                        digit[i+5] -= tmp;

                    }

                }
                else if(i==4&& digit[i]){
                        num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                     if(digit[i+1]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+1]?digit[i+1]:digit[i];
                        num[i] += tmp;
                        num[i+1] += tmp;
                        digit[i] -= tmp;
                        digit[i+1] -= tmp;
                    }
                    if(digit[i+4]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+4]?digit[i+4]:digit[i];
                        num[i] += tmp;
                        num[i+4] += tmp;
                        digit[i] -= tmp;
                        digit[i+4] -= tmp;

                    }
                }
                else if(i==5&& digit[i]){
                        num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                     if(digit[i+2]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+2]?digit[i+2]:digit[i];
                        num[i] += tmp;
                        num[i+2] += tmp;
                        digit[i] -= tmp;
                        digit[i+2] -= tmp;
                    }
                }
                else if(i==7&& digit[i]){
                    num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                    if(digit[i+1]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+1]?digit[i+1]:digit[i];
                        num[i] += tmp;
                        num[i+1] += tmp;
                        digit[i] -= tmp;
                        digit[i+1] -= tmp;
                    }
                }
                else{
                    num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                }
            }
    //        fori(i,10){
    //            cout<<9-i<<":"<<num[i]<<endl;
    //        }
            tmp = 0;
            fori(i,10){
                tmp += num[i]*(9-i);
            }
            if(tmp!=0&&tmp%3==0){
                fori(i,10){
                    fori(j,num[i]){
                    cout<<9-i;
                    }
                }
            cout<<endl;
            }
            else if(tmp==0)
                cout<<0<<endl;
            else
                cout<<-1;

        }
    }
    getchar();
    return 0;
}
=======
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#define fors(i,s) for(int i = 0; i < s.length(); i++)
#define fori(i,n) for(int i = 0; i < n; i++)
using namespace std;
int digit[10];
int num[10];
int main(){
    int T,tmp;
    int N,f;
    scanf("%d",&T);
    while(T--){
        memset(digit,0,sizeof(digit));
        memset(num,0,sizeof(num));
        scanf("%d",&N);
        fori(i,N){
            scanf("%d",&tmp);
            digit[9-tmp]++;
        }
        if(digit[9]==0){
            cout<<-1<<endl;
        }
        else{
            fori(i,10){
                if(i%3==0)
                    num[i] = digit[i];
                else if(i == 1&& digit[i]){
                    num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                    if(digit[i+1]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+1]?digit[i+1]:digit[i];
                        num[i] += tmp;
                        num[i+1] += tmp;
                        digit[i] -= tmp;
                        digit[i+1] -= tmp;
                    }
                    if(digit[i+4]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+4]?digit[i+4]:digit[i];
                        num[i] += tmp;
                        num[i+4] += tmp;
                        digit[i] -= tmp;
                        digit[i+4] -= tmp;

                    }
                    if(digit[i+7]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+7]?digit[i+7]:digit[i];
                        num[i] += tmp;
                        num[i+7] += tmp;
                        digit[i] -= tmp;
                        digit[i+7] -= tmp;
                    }

                }
                else if(i==2&& digit[i]){
                        num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                     if(digit[i+2]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+2]?digit[i+2]:digit[i];
                        num[i] += tmp;
                        num[i+2] += tmp;
                        digit[i] -= tmp;
                        digit[i+2] -= tmp;
                    }
                    if(digit[i+5]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+5]?digit[i+5]:digit[i];
                        num[i] += tmp;
                        num[i+5] += tmp;
                        digit[i] -= tmp;
                        digit[i+5] -= tmp;

                    }

                }
                else if(i==4&& digit[i]){
                        num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                     if(digit[i+1]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+1]?digit[i+1]:digit[i];
                        num[i] += tmp;
                        num[i+1] += tmp;
                        digit[i] -= tmp;
                        digit[i+1] -= tmp;
                    }
                    if(digit[i+4]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+4]?digit[i+4]:digit[i];
                        num[i] += tmp;
                        num[i+4] += tmp;
                        digit[i] -= tmp;
                        digit[i+4] -= tmp;

                    }
                }
                else if(i==5&& digit[i]){
                        num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                     if(digit[i+2]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+2]?digit[i+2]:digit[i];
                        num[i] += tmp;
                        num[i+2] += tmp;
                        digit[i] -= tmp;
                        digit[i+2] -= tmp;
                    }
                }
                else if(i==7&& digit[i]){
                    num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                    if(digit[i+1]!=0 && digit[i]){
                        tmp = digit[i]>digit[i+1]?digit[i+1]:digit[i];
                        num[i] += tmp;
                        num[i+1] += tmp;
                        digit[i] -= tmp;
                        digit[i+1] -= tmp;
                    }
                }
                else{
                    num[i] += digit[i]/3*3;
                    digit[i] -= digit[i]/3*3;
                }
            }
    //        fori(i,10){
    //            cout<<9-i<<":"<<num[i]<<endl;
    //        }
            tmp = 0;
            fori(i,10){
                tmp += num[i]*(9-i);
            }
            if(tmp!=0&&tmp%3==0){
                fori(i,10){
                    fori(j,num[i]){
                    cout<<9-i;
                    }
                }
            cout<<endl;
            }
            else if(tmp==0)
                cout<<0<<endl;
            else
                cout<<-1;

        }
    }
    getchar();
    return 0;
}
>>>>>>> origin/master
