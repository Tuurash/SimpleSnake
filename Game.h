#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define Up 1
#define Down -1
#define Right 2
#define Left -2

void InitGrid(int,int);
void DrawGrid();
void DrawSnake();
void DrawFood();
void random(int&,int&);

#define Max 60


#endif // GAME_H_INCLUDED
