#include <stdio.h>
#include <stdlib.h>


//Funktion zur Einstellung des Boards
void setupboard(int board[20][20])
{

    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            printf("%d ", board[y][x]);
        }
        printf("\n");
    }
}

//Funktion zum Update des neuen Boardstate
void updatedboard(int board[20][20])
{
    int newboard[20][20] = {0};
    for (int y = 1; y < 19; y++)
    {
        for (int x = 1; x < 19; x++)
        {
            int neighbours = checkneighbours(board, x, y);
            if (board[y][x] == 1)
            {
                if (neighbours == 2 || neighbours == 3)
                {
                    newboard[y][x] = 1;
                }
            }
            else
            {
                if (neighbours == 3)
                {
                    newboard[y][x] = 1;
                }
            }
        }
    }
    


    for (int y = 0; y < 20; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            board[y][x] = newboard[y][x];
        }
    }
}

//Funktion um in einem 3x3 Grid um die Zelle nach aktiven oder nicht aktiven Nachbarn zu schauen
int checkneighbours(int board[20][20], int x, int y)
{
    int count = 0;
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            if (board[y + j][x + i] == 1)
            {
                count++;
            }
        }
    }
    return count;
}





int main()
{


// Initialisierung des Boards und der Startposition
    int board[20][20] = {0};
    board[0][0] = 1;
    setupboard(board);
    getchar();

    return 0;
}