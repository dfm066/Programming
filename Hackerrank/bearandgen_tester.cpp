#include <bits/stdc++.h>
using namespace std;
int n;
char inp[500007];
int ok[1007];
int sum[500007][5];
int bsa, bsb, bss;
int p1;
inline int is_ok(int v, int u)
{
    for (int i=1; i<=4; i++)
    {
        if (sum[n][i]-sum[u][i]+sum[v-1][i]>n/4)
        {
            return 0;
        }
    }
    return 1;
}
inline int is_pos(int v)
{
    for (int i=1; i+v-1<=n; i++)
    {
        if (is_ok(i, i+v-1))
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    ok['A']=1;
    ok['C']=2;
    ok['G']=3;
    ok['T']=4;
    assert(scanf("%d", &n)==1);
    assert(n>=4 && n<=500000 && !(n&3));
    assert(scanf("%s", inp+1)==1);
    for (int i=1; i<=n; i++)
    {
        assert(ok[inp[i]]);
    }
    assert(!inp[n+1]);
    assert(scanf("%d", &p1)==EOF);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=4; j++)
        sum[i][j]=sum[i-1][j];
        sum[i][ok[inp[i]]]++;
    }
    bsa=0;
    bsb=n;
    while(bsa<bsb)
    {
        bss=(bsa+bsb)>>1;
        if (is_pos(bss))
        bsb=bss;
        else
        bsa=bss+1;
    }
    printf("%d\n", bsa);
    return 0;
}
