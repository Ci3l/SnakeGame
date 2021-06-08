#include <stdio.h>


char snakeyMap[20][20];

void initializeBoundaries(){
    int x, y;
    for (x = 0; x <= 20; x++){
        for (y = 0; y <= 20; y++){
            if (x == 0 || x == 20 -1 || y == 0 || y == 20){
                snakeyMap[x][y] = 35;
            } else {
                snakeyMap[x][y] = 32;
            }
        }
    }
}

char getPixelValue(int x, int y)
{
    return snakeyMap[x][y];
}

char setPixelValue(int x, int y, char newValue)
{
    snakeyMap[x][y] = newValue;
}

void drawMap()
{
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j <= 20; j++)
        {
            printf("%c", snakeyMap[i][j]);
        }
        printf("\n");
    }
}

