#include<iostream>
#define MAX 10
using namespace std;

void print(int mat[MAX][MAX],int order)
{
        cout<<"\nMatrix  : \n";
        for(int i = 0; i<order; i++)
        {
            for(int j = 0; j<order; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
}

void printSpiral(int mat[MAX][MAX],int order)
{
    int row=0,col=0,dir=1,flg_r=0,flg_c=0;
    int ulim_r=order-1,ulim_c=order-1,llim_c=0,llim_r=0;
    cout<<"\nSpiral Matrix : \n";
    for(int i = 0; i<order; i++)
    {
        if(dir==1)
        {
                while(col<=ulim_c)
                {
                    cout<<" "<<mat[row][col];
                    if(col==ulim_c) break;
                    else col+=dir;
                }
                llim_r+=1;
                row++;
                while(row<=ulim_r)
                {
                    cout<<" "<<mat[row][col];
                    if(row==ulim_r) break;
                    else row+=dir;
                }
                ulim_c-=1;
                col--;
                dir=-1;
        }
        else
        {

            while(col>=llim_c)
                {
                    cout<<" "<<mat[row][col];
                    if(col==llim_c) break;
                    else col+=dir;
                }
                ulim_r-=1;
                row--;
                while(row>=llim_r)
                {
                    cout<<" "<<mat[row][col];
                    if(row==llim_r) break;
                    else row+=dir;
                }
                llim_c+=1;
                col++;
                dir=1;
        }

    }
}

int main()
{
    int matrix[MAX][MAX];
    int order=0;
    cout<<"\nEnter order of matrix : ";
    cin>>order;
    cout<<"\nEnter "<<order<<" x "<<order<<" matrix : \n";
    for(int i=0;i<order;i++)
        for(int j=0;j<order;j++)
        {
            cin>>matrix[i][j];
        }
    print(matrix,order);
    printSpiral(matrix,order);
    return 0;
}
