#include<GL/gl.h>
#include<GL/glut.h>
#include<ctime>
#include <cstdlib>

#include "game.h"

extern int score;

int GridX,GridY;
int snake_length=6;
int PositionX[60]={20,20,20,20,20,20},PositionY[60]={10,19,18,17,16};

bool Food=true;
int foodx,foody;

extern bool GameOver;

short SnakeDirection=Right;



void Unit(int,int);



void InitGrid(int x,int y)
{
    GridX=x;
    GridY=y;

}

void DrawFood()
{

 if(Food=true )
    {
        random(foodx,foody);
        Food=false;
        glColor3f(0.0,1.0,1.0);
        glRectf(foodx,foody,foodx+1,foody+1);
    }
}

void DrawGrid()
{
    for(int x=0;x<GridX;x++)
    {
        for(int y=0;y<GridY;y++)
        {
            Unit(x,y);
        }
    }

}



void Unit(int x,int y)
{
    if(x==0 || y==0 ||x==GridX-1 ||y==GridY-1)
    {
        glLineWidth(3.0);
        glColor3f(1.0,0.0,0.0);
    }
    else
    {
        glLineWidth(1.0);
        glColor3f(1.0,1.0,1.0);
    }

    glBegin(GL_LINE_LOOP);

    glVertex2d(x,y);
    glVertex2d(x+1,y);
    glVertex2d(x+1,y+1);
    glVertex2d(x,y+1);

    glEnd();
}


void DrawSnake()
{
    for(int i=snake_length-1;i>0;i--)
    {
        PositionX[i]=PositionX[i-1];
        PositionY[i]=PositionY[i-1];
    }
    if(SnakeDirection==Up)
        PositionY[0]++;
    else if(SnakeDirection==Down)
        PositionY[0]--;
    else if(SnakeDirection==Left)
        PositionX[0]--;
    else if(SnakeDirection==Right)
        PositionX[0]++;

        for(int i=0;i<snake_length;i++)
        {
            if(i==0)
                {glColor3f(0,1,0);}
            else
                {glColor3f(0,0,1);}

            glRectd(PositionX[i],PositionY[i],PositionX[i]+1,PositionY[i]+1);
        }



     if(PositionX[0]==0 || PositionX[0]==GridX-1 || PositionY[0]==0 || PositionY[0]==GridY-1)
     {
        GameOver=true;
     }
     if(PositionX[0]==foodx && PositionY[0]==foody)
     {
         score++;
         snake_length++;
         if(snake_length>=Max)
           {

            snake_length=Max;}
         Food=true;
     }
}

void random(int &x,int &y)
{
    int _maxX=GridX-2;
    int _maxY=GridY-2;
    int _min=1;


    srand(time(NULL));

    x=_min+rand()%(_maxX-_min);
    y=_min+rand()%(_maxY-_min);

}







