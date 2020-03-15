#include <Gl/gl.h>
#include <Gl/glut.h>
#include <windows.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>
#include<mmsystem.h>


#include "Game.h"


#define Columns 30
#define Rows 30
#define FPS 10

int flag=0;

int score=0;

extern short SnakeDirection; //to excess from Game.cpp

bool GameOver=false;
 void frontscreen();
void DispalyCallback();
void ReshapeCallBack(int,int);
void TimerCallBack(int);
void KeyboardCallBack(unsigned char,int,int);


void drawstring(float x, float y, void *font, char* string)
{
  char *c;

  glRasterPos2f(x,y);
  for(c=string;*c!='\0';c++)
  {
      glutBitmapCharacter(font,*c);
  }

}

 void frontscreen()

{
 glClear(GL_COLOR_BUFFER_BIT);

 glPushMatrix();

//glColor3f(1.0,1.0,1.0);
 char buf[100]={0};

 glColor3f(1.0,1.0,1.0);
 sprintf(buf,"Press Q to START!!");
 drawstring(5,25,GLUT_BITMAP_TIMES_ROMAN_24,buf);

 glColor3f(0.0,1.0,1.0);
 sprintf(buf,"Press W to Move UP");
 drawstring(5,19,GLUT_BITMAP_HELVETICA_18,buf);

 glColor3f(1.0,0.0,1.0);
 sprintf(buf,"Press S to Move Down");
 drawstring(5,17,GLUT_BITMAP_HELVETICA_18,buf);

 glColor3f(1.0,1.0,0.0);
 sprintf(buf,"Press A to Move Left");
 drawstring(5,15,GLUT_BITMAP_HELVETICA_18,buf);

 glColor3f(0.5,1.0,0.5);
 sprintf(buf,"Press D to Move Right");
 drawstring(5,13,GLUT_BITMAP_HELVETICA_18,buf);


 glPopMatrix();

 glutSwapBuffers();

 glFlush();
}

void Init()
{
    glClearColor(0,0,0,1);
    InitGrid(Columns,Rows);


}

int main(int argc,char **argv)

{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(100,500);
    glutInitWindowSize(500,500);
    glutCreateWindow("Snake!");

    glutDisplayFunc(DispalyCallback);

    glutReshapeFunc(ReshapeCallBack);

    glutTimerFunc(0,TimerCallBack,0);
    glutKeyboardFunc(KeyboardCallBack);

    Init();
    glutMainLoop();

    return 0;
}


void DispalyCallback()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(flag==0)
    {
        frontscreen();
    }
    else
    {
   // DrawGrid();
    DrawFood();
    DrawSnake();





    glutSwapBuffers();
    if(GameOver)
    {
        char _score[10];
        itoa(score,_score,10);
        char text[50]="Score:";
        strcat(text,_score);
       MessageBox(NULL,text,"Game Over!",0);
       exit(0);
    }
    }
}

void ReshapeCallBack(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,Columns,0,Rows,-1,1);  // screen size,ratio;
    glMatrixMode(GL_MODELVIEW);
}


void TimerCallBack(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,TimerCallBack,0);
}


void KeyboardCallBack(unsigned char key,int,int)
{
    switch(key)
    {
    case 'w':
        if(SnakeDirection!=Down)
        {
            SnakeDirection=Up;
            break;
        }
    case 's':
        if(SnakeDirection!=Up)
        {
            SnakeDirection=Down;
            break;
        }
    case 'a':
        if(SnakeDirection!=Right)
        {
            SnakeDirection=Left;
            break;
        }
    case 'd':
        if(SnakeDirection!=Left)
        {
            SnakeDirection=Right;
            break;
        }
    case 'q':
        {
            flag=1;
            break;
        }

    }
}
















