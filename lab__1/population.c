#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int startSize;
    int endSize;
    int totalYears = 0;

    // TODO: Prompt for start size
    do
    {
        startSize = get_int("Enter the size of your population: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    do
    {
        endSize = get_int("Enter the maximum size of your population: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    while (startSize < endSize)
    {
        int llamaBorn = startSize / 3;
        int llamaDead = startSize / 4;
        startSize = startSize + llamaBorn - llamaDead;
        totalYears++;
    }

    // TODO: Print number of years
    printf("Years: %d\n", totalYears);
}
