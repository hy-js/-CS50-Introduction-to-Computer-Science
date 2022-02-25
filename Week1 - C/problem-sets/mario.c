#include <cs50.h>
#include <stdio.h>

// Returns
int main(void)
{
    // Prompt for input
    // read int from stdin
    int height;
    do
    {
        height = get_int("Enter pyramid height: ");
    }
    while (height < 1 || height > 8);
    // Confirm within range Height < 9
    // printf("Within range\n");
    // print height - row + row + block + .. + row
    for (int row = 1; row <= height; row++)
    {
        // row = {1 ,2 3}
        for (int column = 0; column < height - row; column++)
        {
            // column = {0, 1}
            printf(" ");
        }
        for (int i = 0; i < row ; i++)
        {
            printf("#");
        }
        printf("  ");
        for (int i = 0; i < row ; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}