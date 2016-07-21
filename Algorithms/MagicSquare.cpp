#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

inline int mod(int no,int div)
{
    if(no>=0) return no%div;
    else return div-1;
}
void magicSquare(int **square,int n)
{
    int i,j,k,l,key;
    if(n%2==0) cout<<"\nOrder is even";
    else{
        for(i=0; i<n;i++)
            for(j=0;j<n;j++)
                square[i][j]=0;
        square[0][(n-1)/2]=1;
        j=(n-1)/2;
        for(key=2; key<=n*n; key++)
        {
            if(i>=1) k=i-1;
            else k=n-1;
            if(j>=1) l=j-1;
            else l=n-1;
            if(square[k][l]>=1) i=mod(i+1,n);
            else{
                i=k;
                j=l;
            }
            square[i][j]=key;
        }
        cout<<"\nMagic square of order "<<n<<" x "<<n<<" :"<<endl;
        for(i=0; i<n;i++){
            for(j=0;j<n;j++)
                printf("%5d",square[i][j]);
            cout<<endl;
        }
    }
    return;
}
int main()
{
    int order=3;
    int **mat;
    cout<<"Enter order : ";
    cin>>order;
    mat=(int**)malloc(order*sizeof(int*));
    for(int i=0;i<order;i++)
    {
        *(mat+i)=(int*)malloc(order*sizeof(int));
    }
    magicSquare(mat,order);
    delete(mat);
    return 0;
}
