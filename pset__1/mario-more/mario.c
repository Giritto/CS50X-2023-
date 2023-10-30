#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, spaces, columns, lines;

    // Make user input the height of the pyramid
    do
    {
        height = get_int("Select the height: ");
    }
    while (height > 8 || height < 1);

    // Printing the pyramid
    for (lines = 0; lines < height; lines++)
    {
        for (spaces = 0; spaces < height - lines - 1; spaces++)
        {
            printf(" ");
        }
        for (columns = 0; columns <= lines; columns++)
        {
            printf("#");
        }
        printf("  ");
        for (columns = 0; columns <= lines; columns++)
        {
            printf("#");
        }
        printf("\n");
    }
}

