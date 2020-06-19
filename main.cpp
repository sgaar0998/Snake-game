#include <iostream>
#include <type_traits>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameover;
int x,y,fruitx,fruity,score;
int width =20;
int height =20;
enum eDire {STOP=0,LEFT,RIGHT,UP,DOWN};
eDire dir;
int tailx[100],taily[100];
int tlen;



void setup()
{
   gameover = false;
   x=width/2;
   y=height/2;
   dir = STOP;
   fruitx= rand()%width;
   fruity= rand()%height;
   score = 0;

}

void draw()
{
    system("cls");
    for(int i=0;i<width+2;i++)
    {cout<<"#";}

    cout<<endl;

    for(int i=0;i<height;i++)
    {
       for(int j=0;j<width;j++)
        {
           if(j==0)
           {cout<<"#";}

           if(i==x && j==y){cout<<"O";}
           else
           if(i==fruitx && j==fruity){cout<<"*";}
           else
           {
               bool print =false;
               for(int q=0;q<tlen;q++)
               {
                   if(tailx[q]==i && taily[q]==j)
                    {
                        cout<<"o";
                        print =true;
                    }
               }
               if(print==false)
                {cout<<" ";}
           }

           if(j==width-1)
           {cout<<"#";}
        }
        cout<<endl;
    }


    for(int i=0;i<width+2;i++)
    {cout<<"#";}
    cout<<endl;    cout<<endl;
    cout<<"SCORE = "<<score;

}
void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
            dir=LEFT;break;

            case 's':
            dir=DOWN;break;

            case 'w':
            dir=UP;break;

            case 'd':
            dir=RIGHT;break;

            case 'x':
            gameover=true;break;
        }
    }

}
void logic()
{
    int prvx=x;
    int prvy=y;


    for(int i=tlen;i>0;i--)
    {

        tailx[i]=tailx[i-1];
        taily[i]=taily[i-1];

    }
    tailx[0]=x;
        taily[0]=y;

    switch(dir)
    {
    case LEFT:
    y=y-1;
    break;

    case RIGHT:
    y=y+1;
    break;

    case UP:
    x=x-1;
    break;

    case DOWN:
    x=x+1;
    break;
    }
    if( x>width || x<0 || y<0 || y>height )
    {gameover=true;}

    for(int q=0;q<tlen;q++)
    {
        if(tailx[q]==x && taily[q]==y)
        {
            gameover=true;
        }
    }

    if(x==fruitx && y==fruity)
    {
        score=score+10;
        fruitx= rand()%width;
        fruity= rand()%height;
        tlen=tlen+1;

    }

}

void endgame()
{
    system("cls");
     for(int i=0;i<width+2;i++)
    {cout<<"#";}

    cout<<endl;

    for(int i=0;i<height;i++)
    {
       for(int j=0;j<width;j++)
        {
           if(j==0)
           {cout<<"#";}



            cout<<"*";


           if(j==width-1)
           {cout<<"#";}
        }
        cout<<endl;
    }


    for(int i=0;i<width+2;i++)
    {cout<<"#";}
    cout<<endl;    cout<<endl;
    cout<<"you loose."<<endl;
    cout<<"YOUR SCORE => "<<score;
}

int main()
{
    setup();
    while(gameover!=true)
    {
        draw();
        input();
        logic();

        Sleep(10);
    }

    if(gameover==true)
    {endgame();}



    return 0;
}
