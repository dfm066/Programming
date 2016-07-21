#include <windows.h>         //header file for windows
#include <stdio.h>                          //C standard library
#include<bhingary.h>

void SetColor(int ForgC);
int main()
{
    int i,j,cnt=1,cnt_1=4;
    SetColor(12);
    while(!kbhit())
    {

        if(cnt_1=-1)
            cnt_1=cnt;
        if(cnt>=5)
        {
            cnt-=cnt_1;
            cnt_1--;
        }
        for(j=4;j>=1;j--)
        {
            switch(j)
            {
                case 1:for(i=1;i<=cnt+j;i++)
                        {
       //                     gotoxy(i,j);
                            printf("=");
                        }
                        break;
                case 2:for(i=1;i<=cnt+cnt_1-j;i++)
                        {
     //                       gotoxy(i,j);
                            printf("=");
                        }
                        break;
                case 3:for(i=1;i<=cnt+cnt_1;i++)
                        {
   //                         gotoxy(i,j);
                            printf("=");
                        }
                        break;
                case 4:for(i=1;i<=cnt;i++)
                        {
 //                         gotoxy(i,j);
                            printf("=");
                        }
                        break;

            }
            printf("\n");
        }
        cnt++;
        Sleep(90);
        system("cls");
    }
    return 0;
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
/*
void main()
{
    int a;
    char ch;
    scanf("%d",&a);
    flushall();
    scanf("%c",&ch);

}
*/
