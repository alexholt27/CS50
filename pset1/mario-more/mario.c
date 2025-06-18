#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int rows = 0; rows < height; rows++)
    {
        for (int spaces = 0; spaces < (height - 1) - rows; spaces++)
        {
            printf(" ");
        }

        for (int left_hash = 0; left_hash < rows + 1; left_hash++)
        {
            printf("#");
        }

        printf("  ");

        for (int right_hash = 0; right_hash < rows + 1; right_hash++)
        {
            printf("#");
        }

        printf("\n");
    }

}
