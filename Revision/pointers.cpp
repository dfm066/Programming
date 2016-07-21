#include<iostream>
using namespace std;

int main(int argc,char **argv){
    int mat[2][3]={{10,20,30},{40,50,60}};
    int (*ptr)[3]=mat;
    char *p[3]={"This","Is","array of pointers"};
    cout<<"\n int mat[2][3]={{10,20,30},{40,50,60}};\n int (*ptr)[3]=mat;"<<endl;
    cout<<" This means mat => |10|20|30|-|40|50|60|"<<endl;
    cout<<"\t\t   |        |-|        |"<<endl;
    cout<<"\t\t    \\______/   \\______/ "<<"\n\t\t\t|\t   |"<<endl;
    cout<<"\t\t      *(p)\t*(p+1)"<<endl;
    cout<<"\n Normal Array notation as MAT[][] : "<<endl;
    cout<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<"\t"<<mat[i][j];
        }
        cout<<endl;
    }
    cout<<"\n Pointer ptr as 2D array ptr[][] : "<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<"\t"<<ptr[i][j];
        }
        cout<<endl;
    }
    cout<<"\n Pointer as double pointer *(*(ptr+i)+j): "<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<"\t"<<*(*(ptr+i)+j);
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Array of Pointer  *p[3] : "<<endl;
    cout<<p[0]<<"\t"<<p[1]<<"\t"<<p[2];
    cout<<"\n*************************NOTE*************************"<<endl;
    cout<<"\n\t*p[3] is different than (*p)[3]\n\t*p[3] is array of 3 pointers\n\t(*p)[3] is pointer to array of 3"<<endl;
    cout<<"\n*************************NOTE*************************";
    cout<<endl;
    return 0;

}
