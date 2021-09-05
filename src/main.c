#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "../inc/map.h"

unsigned int snake_orientation = 3;
int score = 0, speed, fruitx, fruity, level;
int snake_coordinates[1][361];
char pressed_key;

typedef enum { false, true } bool;
bool gameover = false;

void initalize_snake()
{
  snake_coordinates[0][0] = 10;
  snake_coordinates[1][0] = 2;

  snake_coordinates[0][1] = 10;
  snake_coordinates[1][1] = 3;
}
void initalize_apple()
{
  fruitx = 10;
  fruity = 16;
  set_pixel_value(fruitx, fruity, '@');
}

void draw_snake()
{
  int i;
  for (i = 0; i <= ((score + 10) / 10); i++)
  {
    if (snake_coordinates[0][i] != 0 && snake_coordinates[1][i] != 0)
    {
      if (i == ((score + 10) / 10)){
        if (get_pixel_value(snake_coordinates[0][i], snake_coordinates[1][i]) == '*'){
          gameover = true ;
        }
      }
      set_pixel_value(snake_coordinates[0][i], snake_coordinates[1][i], '*');
    }
  }
}

/*
void show_snake_coordinates()
{
  printf("\nsnake's coordinates\n");
  int i, j;
  for (i = 0; i <= ((score + 10) / 10); i++)
  {
    for (j = 0; j < 2; j++)
    {
      printf("snakePostions[%d][%d] ->", j, i);
      printf("%d\n", snake_coordinates[j][i]);
    }
    printf("\n");
  }
}
*/

int get_key_down()
{
  if (kbhit())
  {
    return getch();
  }
  return -1;
}

void new_coordinates_for_snake_head(int newX, int newY)
{
  set_pixel_value(snake_coordinates[0][0], snake_coordinates[1][0], 32); //erase the the tip of the tail of the snake
  for (int i = 0; i <= ((score + 10) / 10); i++)                     //shift the coordinates
  {
    snake_coordinates[0][i] = snake_coordinates[0][i + 1];
    snake_coordinates[1][i] = snake_coordinates[1][i + 1];
  }
  snake_coordinates[0][(score + 10) / 10] = newX; //new coordinates for the head
  snake_coordinates[1][(score + 10) / 10] = newY;
}

void up()
{
  new_coordinates_for_snake_head(snake_coordinates[0][((score + 10) / 10)] - 1, snake_coordinates[1][(score + 10) / 10]);
}
void down()
{
  new_coordinates_for_snake_head(snake_coordinates[0][((score + 10) / 10)] + 1, snake_coordinates[1][(score + 10) / 10]);
}
void left()
{
  new_coordinates_for_snake_head(snake_coordinates[0][(score + 10) / 10], (snake_coordinates[1][(score + 10) / 10]) - 1);
}
void right()
{
  new_coordinates_for_snake_head(snake_coordinates[0][(score + 10) / 10], (snake_coordinates[1][(score + 10) / 10]) + 1);
}

void increase_snake_size()
{
  //increase the size of the snake by one when you eat an apple
  int xOfNewPoint, yOfNewPoint;
  if (snake_coordinates[0][0] == snake_coordinates[0][1])
  {
    yOfNewPoint = snake_coordinates[0][1];
    xOfNewPoint = snake_coordinates[1][0] - 1;
  } //check the orientation of the snake
  else if (snake_coordinates[1][0] == snake_coordinates[1][1])
  {
    xOfNewPoint = snake_coordinates[1][0];
    yOfNewPoint = snake_coordinates[0][0] + 1;
  }
  for (int i = ((score + 10) / 10); i >= 0; i--) //shift the coordinates to make room for the new point
  {
    snake_coordinates[0][i + 1] = snake_coordinates[0][i];
    snake_coordinates[1][i + 1] = snake_coordinates[1][i];
  }
  snake_coordinates[0][0] = yOfNewPoint; //new point
  snake_coordinates[1][0] = xOfNewPoint;
}

void new_coordinates_for_apple()
{
  label1 :
    srand(time(NULL));
    fruitx = (rand() % 18) + 1;
    fruity = (rand() % 18) + 1;
    for (int i = 0; i <= ((score + 10) / 10); i++)
    {
      if (snake_coordinates[0][i] == fruity || snake_coordinates[1][i] == fruitx)
      {
        goto label1;
      }
  }
  set_pixel_value(fruitx, fruity, '@');
}

void checkCoordinates()
{
  //check if you've hit the boundaries
  if (snake_coordinates[0][(score + 10) / 10] == 20 || snake_coordinates[0][(score + 10) / 10] == 0 || snake_coordinates[1][(score + 10) / 10] == 20 || snake_coordinates[1][(score + 10) / 10] == 0)
  {
    gameover = true;
  }
  //check if you've eaten the apple
  else if (snake_coordinates[0][(score + 10) / 10] == fruitx && snake_coordinates[1][(score + 10) / 10] == fruity)
  {
    new_coordinates_for_apple();
    score = score + 10;
    increase_snake_size();
  }
}

void (*snakeMovements[])() = {up, down, left, right};

int main()
{
  printf("CHOOSE THE LEVEL : 1/2/3\n");//choose at which speed the snake will go
  scanf("%d",&level);
  if (level = 0){speed = 5000;}
  if (level = 1){speed = 500;}
  if (level = 2){speed = 50;}
  else {speed = 500;}
  initialize_boundaries(),
  initalize_apple();
  initalize_snake();
  while (!gameover)
  {
    int keyDown = get_key_down();
    system("cls");//erase everything on the powershell
    printf("\nYOUR SCORE : %d\n", score);
    draw_snake();//add the snake's coordinates on the map
    draw_map();
    if (keyDown == 'z')
    {
      snake_orientation = 0;
      (*snakeMovements[snake_orientation])();
      continue;
    }
    if (keyDown == 's')
    {
      snake_orientation = 1;
      (*snakeMovements[snake_orientation])();
      continue;
    }
    if (keyDown == 'q')
    {
      snake_orientation = 2;
      (*snakeMovements[snake_orientation])();
      continue;
    }
    if (keyDown == 'd')
    {
      snake_orientation = 3;
      (*snakeMovements[snake_orientation])();

      continue;
    }
    if (keyDown == 27)
    { 
      break;
    }
    else 
    {
      Sleep(speed);
     (*snakeMovements[snake_orientation])(); //if no key is pressed the snake keep running straight ahead
    }
    checkCoordinates();
    set_pixel_value(fruitx, fruity, '@');
  }
  return 0;
}
