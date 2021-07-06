#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include "../inc/map.h"

unsigned int snakeOrientation = 3;
int score = 0, speed, fruitx, fruity, inputlevel;
int snakeCoordinates[1][361];
char pressedKey;
bool gameover;

void initalizeSnake()
{
  snakeCoordinates[0][0] = 10;
  snakeCoordinates[1][0] = 2;

  snakeCoordinates[0][1] = 10;
  snakeCoordinates[1][1] = 3;
}
void initalizeApple()
{
  fruitx = 10;
  fruity = 16;
  setPixelValue(fruitx, fruity, '@');
}

void drawSnake()
{
  int i;
  for (i = 0; i <= ((score + 10) / 10); i++)
  {
    if (snakeCoordinates[0][i] != 0 || snakeCoordinates[1][i] != 0)
    {
      /*if (i == ((score + 10) / 10)){
        if (getPixelValue(snakeCoordinates[0][i], snakeCoordinates[1][i]) == '*'){
          printf("8");
          gameover = true ;
        }
      }*/
      setPixelValue(snakeCoordinates[0][i], snakeCoordinates[1][i], '*');
    }
  }
}

void showSnakePostions()
{
  printf("snake's positions\n");
  int i, j;
  for (i = 0; i <= ((score + 10) / 10); i++)
  {
    for (j = 0; j < 2; j++)
    {
      printf("snakePostions[%d][%d] ->", j, i);
      printf("%d\n", snakeCoordinates[j][i]);
    }
    printf("\n");
  }
}

int GetKeyDown()
{
  if (kbhit())
  {
    return getch();
  }
  return -1;
}

void newCoordinatesForSnakeHead(int newX, int newY)
{
  setPixelValue(snakeCoordinates[0][0], snakeCoordinates[1][0], 32); //erase the the tip of the tail of the snake
  for (int i = 0; i <= ((score + 10) / 10); i++)                     //shift the coordinates
  {
    snakeCoordinates[0][i] = snakeCoordinates[0][i + 1];
    snakeCoordinates[1][i] = snakeCoordinates[1][i + 1];
  }
  snakeCoordinates[0][(score + 10) / 10] = newX; //new coordinates for the head
  snakeCoordinates[1][(score + 10) / 10] = newY;
}

void up()
{
  newCoordinatesForSnakeHead(snakeCoordinates[0][((score + 10) / 10)] - 1, snakeCoordinates[1][(score + 10) / 10]);
}
void down()
{
  newCoordinatesForSnakeHead(snakeCoordinates[0][((score + 10) / 10)] + 1, snakeCoordinates[1][(score + 10) / 10]);
}
void left()
{
  newCoordinatesForSnakeHead(snakeCoordinates[0][(score + 10) / 10], (snakeCoordinates[1][(score + 10) / 10]) - 1);
}
void right()
{
  newCoordinatesForSnakeHead(snakeCoordinates[0][(score + 10) / 10], (snakeCoordinates[1][(score + 10) / 10]) + 1);
}

void increaseSnakeSize()
{
  //increase the size of the snake by one when you eat an apple
  int xOfNewPoint, yOfNewPoint;
  if (snakeCoordinates[0][0] == snakeCoordinates[0][1])
  {
    yOfNewPoint = snakeCoordinates[0][1];
    xOfNewPoint = snakeCoordinates[1][0] - 1;
  } //check the orientation of the snake
  else if (snakeCoordinates[1][0] == snakeCoordinates[1][1])
  {
    xOfNewPoint = snakeCoordinates[1][0];
    yOfNewPoint = snakeCoordinates[0][0] + 1;
  }
  for (int i = ((score + 10) / 10); i >= 0; i--) //shift the coordinates to make room for the new point
  {
    snakeCoordinates[0][i + 1] = snakeCoordinates[0][i];
    snakeCoordinates[1][i + 1] = snakeCoordinates[1][i];
  }
  snakeCoordinates[0][0] = yOfNewPoint; //new point
  snakeCoordinates[1][0] = xOfNewPoint;
}

void newCoordinatesForApple()
{
  fruitx = (rand() % (19)) + 1;
  fruity = (rand() % (19)) + 1;
  setPixelValue(fruitx, fruity, '@');
}

void checkCoordinates()
{
  //check if you've hit the boundaries
  if (snakeCoordinates[0][(score + 10) / 10] == 20 || snakeCoordinates[0][(score + 10) / 10] == 0 || snakeCoordinates[1][(score + 10) / 10] == 20 || snakeCoordinates[1][(score + 10) / 10] == 0)
  {
    gameover = true;
  }
  //check if you've eaten the apple
  else if (snakeCoordinates[0][(score + 10) / 10] == fruitx && snakeCoordinates[1][(score + 10) / 10] == fruity)
  {
    score = score + 10;
    increaseSnakeSize();
    newCoordinatesForApple();
  }
}

void (*snakeMovements[])() = {up, down, left, right};

int main()
{
  printf("CHOOSE THE LEVEL : 1/2/3\n");//choose at which speed the snake will go
  scanf("%d",&inputlevel);
  if (inputlevel = 0){speed = 5000;}
  if (inputlevel = 1){speed = 500;}
  if (inputlevel = 2){speed = 50;}
  else {speed = 500;}
  initializeBoundaries(),
  initalizeApple();
  initalizeSnake();
  while (!gameover)
  {
    int keyDown = GetKeyDown();
    system("cls");//erase everything on the powershell
    printf("\nYOUR SCORE : %d\n", score);
    drawSnake();//add the snake's coordinates on the map
    drawMap();
    if (keyDown == 'z')
    {
      snakeOrientation = 0;
      (*snakeMovements[snakeOrientation])();
      checkCoordinates();
      system("cls");
      continue;
    }
    if (keyDown == 's')
    {
      snakeOrientation = 1;
      (*snakeMovements[snakeOrientation])();
      checkCoordinates();
      system("cls");
      continue;
    }
    if (keyDown == 'q')
    {
      snakeOrientation = 2;
      (*snakeMovements[snakeOrientation])();
      checkCoordinates();
      system("cls");
      continue;
    }
    if (keyDown == 'd')
    {
      snakeOrientation = 3;
      (*snakeMovements[snakeOrientation])();
      checkCoordinates();
      system("cls");
      continue;
    }
    if (keyDown == 27)
    {
      break;
    }
    Sleep(speed);
    (*snakeMovements[snakeOrientation])(); //if no key is pressed the snake keep running straight ahead
    checkCoordinates();
  }
  showSnakePostions();
  return 0;
}
