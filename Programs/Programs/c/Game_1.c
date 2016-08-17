#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<bhingary.h>
void frame();
main()
{
    int flg=0,pos_x_1=3,pos_x_2=3,pos_ball_x=6,pos_ball_y=2,dir_x=1,dir_y=1;
    char ch;
    system("cls");
    printf("\n Instructions :\n\n  Controls =>   Player 1: 6 to move forward 4 to move backward");
    printf("\n\n\t\tPlayer 2: d to move forward a to move backward\n\n  Press ESC to EXIT from GAME\n\n Press Any Key To Start the Game ");
    getch();
    system("cls");
 R:   while(!kbhit())
    {
        frame();
        gotoxy(pos_x_1*2,1);
        printf(" ______ ");
        gotoxy(pos_x_1*2,2);
        printf("(______)");
        gotoxy(pos_x_2*2,18);
        printf(" ______ ");
        gotoxy(pos_x_2*2,19);
        printf("(______)");
        gotoxy(pos_ball_x+dir_x,pos_ball_y+dir_y);
        printf("*");
        if(pos_ball_x>=pos_x_1*2-1&&pos_ball_x<=pos_x_1*2+8&&pos_ball_y==4)
            dir_y=1;
        else if(pos_ball_y==17&&pos_ball_x>=pos_x_2*2-1&&pos_ball_x<=pos_x_2*2+8)
            dir_y=-1;
        if(pos_ball_x==2)
            dir_x=1;
        else if(pos_ball_x==28)
            dir_x=-1;
        if(dir_y==-1)
            pos_ball_y--;
        else
            pos_ball_y++;
        if(dir_x==1)
            pos_ball_x++;
        else
            pos_ball_x--;
        if(pos_ball_y==1||pos_ball_y==19)
            {
                    if(pos_ball_y==1)
                        flg=2;
                    else
                        flg=1;

                    goto end;
            }
        Sleep(150);
        system("cls");
    }
    ch=getch();
    if(ch!=27)
    {
        switch(ch)
        {
            case 52:if(pos_x_1>1)
                    pos_x_1--;
                    break;
            case 54:if(pos_x_1<11)
                    pos_x_1++;
                    break;
            case 'd':if(pos_x_2<11)
                     pos_x_2++;
                     break;
            case 'a':if(pos_x_2>1)
                     pos_x_2--;
                     break;
        }
         goto R;
     }
     end :switch(flg)
     {
            case 1:gotoxy(10,21);
                    printf("Game Over\n\tPlayer 1 Wins");
                    break;
            case 2:gotoxy(10,21);
                    printf("Game Over\n\tPlayer 2 Wins");
                    break;
     }
    // Sleep(3000);
     if(flg==0)
        system("cls");
     printf("\n Thank You For Playing Game");
     getch();
}
void frame()
{
    int i,j;
    for(i=0;i<=20;i++)
    {
        for(j=0;j<=30;j++)
        {
            if(i==0&&j==1)
               printf("#");
            else if(i==0&&j==30)            {
                printf("#");            }
            else if(i==20&&j==1)
                printf("#");
            else if(i==20&&j==30)
                printf("#");
            else if(j!=0&&(i==0||i==20))
                printf("=");
            else if(j==1||j==30)
                printf("|");
            else
                printf(" ");

        }
        printf("\n");
    }
}
