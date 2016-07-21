#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<bhingary.h>
int x,y,flg=0,pos_x_1=3,pos_x_2=3,pos_ball_x=6,pos_ball_y=2,dir_x=1,dir_y=1;
char ch,obj[20][28],obj_1='=',obj_2=' ';
void frame();
void level();
void SetColor(int ForgC);
main()
{
    int color[2],option,i;
    system("cls");
    printf("\n Instructions :\n\n  Controls =>   Player 1: 6 to move forward 4 to move backward");
    printf("\n\n\t\tPlayer 2: d to move forward a to move backward\n\n  Press ESC to EXIT from GAME\n\n Press Any Key To Start the Game ");
    getch();
    system("cls");
    printf("\n\n1.Blue\n2.Green\n3.Sky Blue\n4.Red\n5.Purple\n6.Yellow");
    for(i=0;i<2;i++)
    {
        printf("\nChoose the Player %d Color :",i+1);
        scanf("%d",&option);
        switch(option)
        {
            case 1:color[i]=1;
                    break;
            case 2:color[i]=2;
                    break;
            case 3:color[i]=3;
                    break;
            case 4:color[i]=4;
                    break;
            case 5:color[i]=5;
                    break;
            case 6:color[i]=6;
                    break;
        }
    }


//    level();
    while(1)
    {
        while(!kbhit())
        {
            frame();
 /*           for(y=7;y<12;y++)             // Obstacle
            {
                for(x=2;x<30;x++)
                {
                    gotoxy(x,y);
                    if(x+y>10&&y-x<8&&x-y<21&&x+y<39)
                     {
     //                    obj[y][x]=obj_1;
                         printf("%c",obj[y][x]);
                     }
                    else
                     {
     //                    obj[y][x]=obj_2;
                         printf("%c",obj[y][x]);
                     }
                }
            }*/
            SetColor(color[0]);
            gotoxy(pos_x_1*2,1);
            printf(" ______ ");
            gotoxy(pos_x_1*2,2);
            printf("(______)");
           SetColor(color[1]);
            gotoxy(pos_x_2*2,18);
            printf(" ______ ");
            gotoxy(pos_x_2*2,19);
            printf("(______)");

            for(y=7;y<9;y++)
            {
                for(x=2;x<30;x++)
                {
                    if(obj[y][x]==obj_1)
                   {
                        if(pos_ball_x==x&&pos_ball_y==y)
                        {
                            if((dir_y==1&&dir_x==1)||(dir_y==1&&dir_x==-1))
                            {
                                dir_y=-1;
                            }
                            else if((dir_y==-1&&dir_x==-1)||(dir_y==-1&&dir_x==1))
                            {
                              dir_y=1;
                            }
                            obj[y][x]=obj_2;
                        }
                    }
                }
            }
            SetColor(12);
            gotoxy(pos_ball_x+dir_x,pos_ball_y+dir_y);
            printf("*");
            if(pos_ball_x==obj[y][x]||(pos_ball_x>=pos_x_1*2-1&&pos_ball_x<=pos_x_1*2+8&&pos_ball_y==4))
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
                }
            SetColor(7);
            switch(flg)
            {
                case 1:gotoxy(10,21);
                       printf("Game Over\n\tPlayer 1 Wins");
                       getch();
                       return;
                case 2:gotoxy(10,21);
                       printf("Game Over\n\tPlayer 2 Wins");
                       getch();
                       return;
            }
            Sleep(200);
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
                case 100:if(pos_x_2<11)
                         pos_x_2++;
                         break;
                case 97:if(pos_x_2>1)
                        pos_x_2--;
                        break;
            }
        }
        else
        {
            SetColor(12);
            printf("\n Thank you for playing Game.");
            return;
        }
    }
}
void frame()
{
    int i,j;
    SetColor(15);
    for(i=0;i<=20;i++)
    {
        for(j=0;j<=30;j++)
        {
            if(i==0&&j==1)
               printf("#");
            else if(i==0&&j==30)
                printf("#");
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
void level()
{
      for(y=7;y<9;y++)
            {
                for(x=2;x<30;x++)
                {
                    gotoxy(x,y);
                    if(x!=5&&x!=6&&x!=7&&x!=12&&x!=13&&x!=14&&x!=20&&x!=21&&x!=22)
                 //    {
                         obj[y][x]=obj_1;
                //         printf("%c",obj[y][x]);
                //     }
                //    else
                //     {
                //         obj[y][x]=obj_2;
                //         printf("%c",obj[y][x]);
                //     }
                }
            }
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

