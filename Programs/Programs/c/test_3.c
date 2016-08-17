//      Efficient Matrix
/*
#include <stdio.h>
int main(void){

int j=9;
int k,l;
for(k=0;k<j;k++)
{
    for(l=0;l<j;l++)
        printf("%c", k==l || j-l-1==k?'#':' ');
    printf("\n");
}
return 0;
}
*/
/////////////////////////////////////////////////////////////////

//      Smallest Number without comparision
/*#include<stdio.h>
#define CHAR_BIT 8

//Function to find minimum of x and y
int min(int x, int y)
{
  return  y+((x - y)&((x - y)>>(sizeof(int) * CHAR_BIT - 1)));
}

// Function to find minimum of 3 numbers x, y and z
int smallest(int x, int y, int z)
{
    return min(x, min(y, z));
}

int main()
{
   int x,y,z;
   printf("\n Enter 3 No: ");
   scanf("%d%d%d",&x,&y,&z);
   printf("Minimum of 3 numbers is %d", smallest(x, y, z));
   return 0;
}
#include<windows.h>
#include<stdio.h>

void SetColor(int);
void main()
{
    int i;
 //   for(i=1;i<7;i++)
 //   {
        SetColor(14);
        printf("Hello World");
 //   }
}
void SetColor(int ForgC)
{
     WORD wColor;
                          //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                           //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                     //Mask out all but the background attribute, and add in the foreground color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
*/
void main()
{

    char ch='A';
    printf("%d",ch-64);
}

