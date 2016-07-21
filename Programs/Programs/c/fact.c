long fact(int no)
{
    if(no==0)
        return 1;
    else
        return(no*fact(no-1));
}
int main()
{
    long f,tmp;
    int no,pow=0;
    scanf("%d",&no);
    f=fact(no);
    tmp=f;
    while(tmp%10==0)
    {
        tmp/=10;
        pow++;
    }
    printf("\n Factorial of %d  : %ld\n %ld x 10 ^ %d",no,f,tmp,pow);
}
