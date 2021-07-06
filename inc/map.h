#include <stdio.h>

char snakeyMap[21][21];//the whole map

void initializeBoundaries(){
    int x, y;
    for (x = 0; x <= 20; x++){
        for (y = 0; y <= 20; y++){
            if (x == 0 || x == 20 || y == 0 || y == 20 ){
                snakeyMap[x][y] = 35;
            } else {
                snakeyMap[x][y] = 32;
            }
        }
    }
}

char getPixelValue(int x, int y)
{
    //get the value of an element in the snakey map
    return snakeyMap[x][y];
}

char setPixelValue(int x, int y, char newValue)
{
    //set the value of an elemeent in the snakey map
    snakeyMap[x][y] = newValue;
}

void drawMap()
{
    //print the map
    int i,j;
    for (i = 0; i <= 20; i++)
    {
        printf("\n");
        for (j = 0; j <= 20; j++)
        {
            printf("%c ", snakeyMap[i][j]);
        }
    }
}

/*if (i == ((score + 10) / 10)){
        if (getPixelValue(snakeCoordinates[0][i], snakeCoordinates[1][i]) == '*'){
          printf("8");
          gameover = true ;
        }
      }*/