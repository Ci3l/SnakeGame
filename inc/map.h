#include <stdio.h>

char snakeyMap[21][21];//the whole map

void initialize_boundaries(){
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

char get_pixel_value(int x, int y)
{
    //get the value of an element in the snakey map
    return snakeyMap[x][y];
}

char set_pixel_value(int x, int y, char newValue)
{
    //set the value of an elemeent in the snakey map
    snakeyMap[x][y] = newValue;
}

void draw_map()
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