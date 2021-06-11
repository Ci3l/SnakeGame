#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int GetKeyDown()
{
    if (kbhit())
    {
        return getch();
    }
    return -1;
}

int main(int argc, char **argv)
{
    while (1)
    {
        int keyDown = GetKeyDown();
        if (keyDown == 'a')
        {
            printf("HELLO\n");
        }
        if (keyDown == 'b')
        {
            printf("HI\n");
        }
        Sleep(1000 / 30);
        printf("da");
    }   
}