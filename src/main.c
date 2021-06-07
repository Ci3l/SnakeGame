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

void initalizeSnake();
void initalizeApple();
void controlHandler(char key);

void setSnakePosition(int,int);

void up();
void down();
void left();
void right();

int main()
{
  initializeBoundaries();
  initalizeSnake();
  initalizeApple();
  drawMap();
  while (gameover == false){
    scanf(" %c", &pressedKey);
    if (pressedKey == 'r'){
      up();
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
  sizeOfSP = sizeof(snakePositions) / sizeof(int);
  for (int i = 0; i <= sizeOfSP; i++){
    snakePositions[i][0] = snakePositions[i - 1][0];
    snakePositions[i][1] = snakePositions[i - 1][1];
  }
  sizeOfSP = sizeof(snakePositions) / sizeof(int);
  snakePositions[sizeOfSP + 1][0] = newX;
  snakePositions[sizeOfSP + 1][1] = newY;
}

void drawSnake(){
sizeOfSP = sizeof(snakePositions) / sizeof(int);
int i, j;
for (i = 0; i < sizeOfSP; i++){
  setPixelValue(snakePositions[i][0],snakePositions[i][1],'*');
}
}


void initalizeApple(){
  fruitx = 10;
  fruity = 16;
  setPixelValue(fruitx, fruity, '@');
}

void controlHandler(char key){
  void(* snakeMovements[])() = {up,down,left,right};
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