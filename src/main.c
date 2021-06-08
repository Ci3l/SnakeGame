#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../inc/map.h" 
int score;
bool gameover;
int fruitx,fruity;
int snakePositions[400][1];
int sizeOfSP ;
char pressedKey;

void showSnakePostions();

void initalizeSnake();
void initalizeApple();
void controlHandler(char key);

void setSnakePosition(int,int);

void drawSnake();

void up();
void down();
void left();
void right();

int main()
{
  initializeBoundaries();
  initalizeSnake();
  showSnakePostions();
  initalizeApple();
  drawMap();
  while (gameover == false){
    scanf(" %c", &pressedKey);
    if (pressedKey == 'r'){
      showSnakePostions();
      setSnakePosition(10, 4);
      showSnakePostions();
      drawSnake();
      drawMap();
      gameover = true;
    }
    controlHandler(pressedKey);
  } 
  return 0;
}

void initalizeSnake(){
  snakePositions[0][0] = 10;
  snakePositions[0][1] = 2;
  setPixelValue(snakePositions[0][0], snakePositions[0][1], '*');
  snakePositions[1][0] = 10;
  snakePositions[1][1] = 3;
  setPixelValue(snakePositions[1][0], snakePositions[1][1], '*');
}

void setSnakePosition(int newX, int newY){
  sizeOfSP = (sizeof(snakePositions) / sizeof(int))/2;
  for (int i = 0; i <= sizeOfSP; i++){
    snakePositions[i][0] = snakePositions[i + 1][0];
    snakePositions[i][1] = snakePositions[i + 1][1];
  }
  sizeOfSP = (sizeof(snakePositions) / sizeof(int))/2;
  snakePositions[sizeOfSP + 1][0] = newX;
  snakePositions[sizeOfSP + 1][1] = newY;
}


void initalizeApple(){
  fruitx = 10;
  fruity = 16;
  setPixelValue(fruitx, fruity, '@');
}



void drawSnake()
{
  sizeOfSP = sizeof(snakePositions) / sizeof(int);
  int i, j;
  for (i = 0; i <= sizeOfSP; i++)
  {
    setPixelValue(snakePositions[i][0], snakePositions[i][1], '*');
  }
}

void controlHandler(char key){
  void(*snakeMovements[])() = {up,down,left,right};
}

void up(){
  sizeOfSP = sizeof(snakePositions) / sizeof(int);
  setSnakePosition(snakePositions[sizeOfSP][0],(snakePositions[sizeOfSP][1])-1);
  drawSnake();
  drawMap();
}
void down(){
  sizeOfSP = sizeof(snakePositions) / sizeof(int);
  setSnakePosition(snakePositions[sizeOfSP + 1][0], snakePositions[sizeOfSP][1]);
  drawSnake();
  drawMap();
}
void left(){
  sizeOfSP = sizeof(snakePositions) / sizeof(int);
  setSnakePosition(snakePositions[sizeOfSP + 1][0], snakePositions[sizeOfSP][1]);
  drawSnake();
  drawMap();
}
void right(){
  sizeOfSP = sizeof(snakePositions) / sizeof(int);
  setSnakePosition(snakePositions[sizeOfSP + 1][0], snakePositions[sizeOfSP][1]);
  drawSnake();
  drawMap();
}

void showSnakePostions()
{
  printf("snake's positions\n");
  int i, j;
  for (i = 0; i <= 3; i++)
  {
    for (j = 0; j <= 1; j++)
    {
      printf("snakePostions[%d][%d] ->",i,j);
      printf("%d\n", snakePositions[i][j]);
    }
    printf("\n");
  }
 
  printf("\n%d\n", (sizeof(snakePositions) / sizeof(int)) / 2);
}
