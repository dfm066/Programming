#include<iostream>
#include<stdlib.h>
using namespace std;

	template<class T>
	int partition( T a[],int low,int high )
	{
		T num=a[low];
		int i=low+1;
		int j=high;
		T temp;

		while( 1 )
		{

		       while( i<high && num>a[i] )
		              i++;

		       while( num<a[j] )
		              j--;

		       if( i<j )
		       {
		          temp=a[i];
		          a[i]=a[j];
		          a[j]=temp;
		       }
		       else
		       {
		          temp=a[low];
		          a[low]=a[j];
		          a[j]=temp;
                  return(j);
		       }
		}
	}

	template<class T>
	void Quick(T a[],int low,int high )
	{
		int j;

		if( low<high )
		{
		    j=partition(a,low,high);
		    Quick(a,low,j-1);
		    Quick(a,j+1,high );
		}
	}

	int main()
	{
		int N;



                cout<<"Enter array size : ";
		cin>>N;

		int *p=new int[N];
        int i;
		cout<<"\nEnter "<<N<<" int no's..\n";
		for(i=0; i<N; i++ )
		    cin>>p[i];

		cout<<"\nArray before sorting is..\n";
		while(i<N)
		{
		    cout<<p[i]<<"\n";
	            i++;
		}
		Quick( p,0,N-1 );

		cout<<"\nArray after sorting is..\n";
		for(i=0; i<N; i++ )
		    cout<<p[i]<<"\n";

	/*	double *q=new double[N];

		cout<<"\nEnter "<<N<<" double no's..\n";
		for(i=0; i<N; i++ )
		    cin>>q[i];

		cout<<"\nArray before sorting is..\n";
		for(i=0; i<N; i++ )
		    cout<<q[i]<<"\n";

		Quick( q,0,N-1 );

		cout<<"\nArray after sorting is..\n";
		for(i=0; i<N; i++ )
		    cout<<q[i]<<"\n";

*/
                return 0;

	}
