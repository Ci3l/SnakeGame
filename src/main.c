#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../inc/map.h" 
int score = 0;
bool gameover;
int fruitx,fruity;
int snakePositions[1][400];
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

int main(){
  initializeBoundaries(),
  initalizeApple();
  initalizeSnake();
  while (gameover != true){
    drawSnake();
    drawMap();
    /*printf("inital positions\n");
    showSnakePostions();

    initializeBoundaries();
    initalizeSnake();

    printf("initialized\n");
    showSnakePostions();

    drawSnake();

    initalizeApple()dddd;
    drawMap();

    printf("test zone\n");

    setSnakePosition(10,4);
    showSnakePostions();
    drawSnake();
    drawMap();
    */

    if (kbhit)
    {
      char ch = getch();    
      if ((int)ch == 27) 
        break;
      controlHandler(ch);
    }
  }
  return 0;
}

void initalizeSnake(){
  snakePositions[0][0] = 10;
  snakePositions[1][0] = 2;
  
  snakePositions[0][1] = 10;
  snakePositions[1][1] = 3;
}
void initalizeApple(){
  fruitx = 10;
  fruity = 16;
  setPixelValue(fruitx, fruity, '@');
}

void drawSnake(){
  sizeOfSP = (sizeof(snakePositions) / sizeof(int)) / 2;
  int i;
  for (i = 0; i <= sizeOfSP; i++){
    if (snakePositions[0][i] != 0 || snakePositions[1][i] != 0){
      printf("x = %d y = %d\n", snakePositions[0][i], snakePositions[1][i]);
      setPixelValue(snakePositions[0][i], snakePositions[1][i], '*');
    }
    
  }
}

void setSnakePosition(int newX, int newY){
  sizeOfSP = (sizeof(snakePositions) / sizeof(int))/2;
  setPixelValue(snakePositions[0][0], snakePositions[1][0], 32);
  for (int i = 0; i <= sizeOfSP; i++){
    snakePositions[0][i] = snakePositions[0][i + 1];
    snakePositions[1][i] = snakePositions[1][i + 1];
  }
  snakePositions[0][(score + 10)/10] = newX;
  snakePositions[1][(score + 10)/10] = newY;
}

void showSnakePostions()
{
  printf("snake's positions\n");
  int i, j;
  for (i = 0; i <= 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      printf("snakePostions[%d][%d] ->", i, j);
      printf("%d\n", snakePositions[j][i]);
    }
    printf("\n");
  }

  printf("\n%d\n", (sizeof(snakePositions) / sizeof(int)) / 2);
}

void controlHandler(char key){
  unsigned int movement = 0;
  void (*snakeMovements[])() = {up, down, left, right};
  printf("\n%c\n",key);
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
  printf("%d",movement);
  (*snakeMovements[movement])();
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

