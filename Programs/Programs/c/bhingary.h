#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h> //  header file for gotoxy
#include <stdio.h>  //header file for standard input output

 void bhringary();
 void gotoxy();
int pos_x=0,pos_y=0;
  COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
 void gotoxy(int x,int y)
 {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void bhingary()
{
    int i;
    char ch='5';
 N: while(!kbhit())
    {
        for(i=0;i<4;i++)
        {
            Sleep(30);
            system("cls");
            switch(i)
            {
                case 0:gotoxy(pos_x,pos_y);
                       printf("\\");
                       break;
                case 1:gotoxy(pos_x,pos_y);
                        printf("|");
                        break;
                case 2:gotoxy(pos_x,pos_y);
                        printf("/");
                        break;
                case 3:gotoxy(pos_x,pos_y);
                        printf("-");
                        break;
            }
        }
    }
    ch=getch();
    if(ch==50||ch==52||ch==54||ch==56)
    {
        switch(ch)
        {
            case 50:pos_y++;
                    break;
            case 52:pos_x--;
                    break;
            case 54:pos_x++;
                    break;
            case 56:pos_y--;
                    break;
        }
         goto N;
     }
}
