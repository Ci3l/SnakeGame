#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../inc/map.h" 
int score = 0;
bool gameover;
int fruitx,fruity;
int snakeCoordinates [1][400];
char pressedKey;

void showSnakePostions();

void initalizeSnake();
void initalizeApple();
void controlsHandler(char key);

void addSnakeCoordinate(int,int);

void drawSnake();

void up();
void down();
void left();
void right();

int main(){
  initializeBoundaries(),
  initalizeApple();
  initalizeSnake();
  while (gameover != true){
    drawSnake();
    drawMap();
    if (kbhit)
    {
      char ch = getch();    
      if ((int)ch == 27) 
        break;
      controlsHandler(ch);
    }
  }
  return 0;
}

void initalizeSnake(){
  snakeCoordinates [0][0] = 10;
  snakeCoordinates [1][0] = 2;
  
  snakeCoordinates [0][1] = 10;
  snakeCoordinates [1][1] = 3;
}
void initalizeApple(){
  fruitx = 10;
  fruity = 16;
  setPixelValue(fruitx, fruity, '@');
}

void drawSnake(){
  int i;
  for (i = 0; i <= ((score + 10) / 10); i++)
  {
    if (snakeCoordinates [0][i] != 0 || snakeCoordinates [1][i] != 0){
      setPixelValue(snakeCoordinates [0][i], snakeCoordinates [1][i], '*');
    }
  }
}

void addSnakeCoordinate (int newX, int newY){
  setPixelValue(snakeCoordinates [0][0], snakeCoordinates [1][0], 32);
  for (int i = 0; i <= ((score + 10) / 10); i++)
  {
    snakeCoordinates [0][i] = snakeCoordinates [0][i + 1];
    snakeCoordinates [1][i] = snakeCoordinates [1][i + 1];
  }
  snakeCoordinates [0][(score + 10)/10] = newX;
  snakeCoordinates [1][(score + 10)/10] = newY;
}

void showSnakePostions()
{
  printf("snake's positions\n");
  int i, j;
  for (i = 0; i <= 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      printf("snakePostions[%d][%d] ->", j, i);
      printf("%d\n", snakeCoordinates [j][i]);
    }
    printf("\n");
  }
}

void controlsHandler(char key){
  unsigned int movement = 0;
  void (*snakeMovements[])() = {up, down, left, right};
  switch (key){
  case 'z': 
    movement = 0;
    break;
  case 's' :
    movement = 1;
    break;
  case 'q' :
    movement = 2;
    break;
  case 'd' :
    movement = 3;
    break;
  }
  (*snakeMovements[movement])();
}

void up(){
  addSnakeCoordinate (snakeCoordinates [0][((score + 10) / 10)] - 1, snakeCoordinates [1][(score + 10) / 10]);
}
void down(){
  addSnakeCoordinate (snakeCoordinates [0][((score + 10) / 10)] + 1, snakeCoordinates [1][(score + 10) / 10]);
}
void left(){ 
  addSnakeCoordinate (snakeCoordinates [0][(score + 10) / 10], (snakeCoordinates [1][(score + 10) / 10]) - 1); 
}
void right(){
  addSnakeCoordinate (snakeCoordinates [0][(score + 10) / 10], (snakeCoordinates [1][(score + 10) / 10]) + 1);
}

