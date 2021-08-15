#include <cs50.h>
#include <stdio.h>

int died(int pop)
{
    return (pop / 4);
}

int born(int pop)
{
    return (pop / 3);
}

int main(void)
{
    int start_size = 0;
    int end_size = 0;
    int years = 0;
    int births;
    int buried;

    // Prompt for start size
    while (start_size < 9)
    {
        start_size = get_int("Start size: ");
    }

    // Prompt for end size
    while (end_size < start_size)
    {
        end_size = get_int("End size: ");
    }

    // Calculate number of years until we reach threshold
    while (start_size < end_size)
    {
        births = born(start_size);
        buried = died(start_size);
        start_size = start_size - buried + births;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %d\n", years);
}