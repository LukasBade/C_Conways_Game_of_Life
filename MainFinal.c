#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 

int checkneighbours(int board[20][20], int x, int y);

void console_clear_screen()
{
    printf("\x1b[H\x1b[J");
}

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

int checkneighbours(int board[20][20], int x, int y)
{
    int count = 0;
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++) {
            if (i == 0 && j == 0) continue;
            
            if (board[y + j][x + i] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int board[20][20] = {0};
    int max_generations = 0;
    char command;
    int pos_x, pos_y;

    printf("Anzahl der zu simulierenden Generationen: ");
    if (scanf("%d", &max_generations) != 1) return 1;

    printf("Zellen hinzufuegen mit 'a [x] [y]' (Beenden mit 'e'):\n");
    while (1) {
        if (scanf(" %c", &command) != 1) break;

        if (command == 'e') {
            break; 
        } 
        else if (command == 'a') {
            if (scanf("%d %d", &pos_x, &pos_y) == 2) {
                if (pos_x >= 0 && pos_x < 20 && pos_y >= 0 && pos_y < 20) {
                    board[pos_y][pos_x] = 1;
                    printf("Zelle bei (%d|%d) platziert.\n", pos_x, pos_y);
                }
            }
        }
    }

    setupboard(board);
    Sleep(1500); 

    for (int g = 0; g < max_generations; g++) 
    {
        updatedboard(board); // newgen
        
        console_clear_screen(); 
        printf("Generation: %d / %d\n", g + 1, max_generations);
        setupboard(board);       
        
        Sleep(400); 
    }

    return 0;
}
