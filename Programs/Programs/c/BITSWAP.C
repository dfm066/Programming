void main()
{
	int i=0,cnt,j,k=0,l,no,temp,bin[10];
	clrscr();
	printf("\n Enter No :");
	scanf("%d",&no);
	while(no)
	{
	  bin[i]=no%2;
	  no/=2;
	  k++;
	  i++;
	}
	printf("\n Binary No: ");
	for(j=i-1;j>=0;j--)
	{
		printf("%d",bin[j]);
	}
	printf("\n After swapping : ");
	cnt=i/2;
	l=i-1;
	while(cnt>0)
	{
	     temp=bin[l];
	     bin[l]=bin[l-1];
	     bin[l-1]=temp;
	     l=l-2;
	     cnt--;
	}
	for(j=i-1;j>=0;j--)
	{
		printf("%d",bin[j]);
	}
	getch();
}