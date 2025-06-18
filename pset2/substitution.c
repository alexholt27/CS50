#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please provide a key for encryption.\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("The key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key should contain only letters.\n");
            return 1;
        }

        for (int j = i + 1; j < len; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("No duplicate values allowed.\n");
                return 1;
            }
        }
    }

    string key = argv[1];
    
    string plain = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plain); i < len; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                printf("%c", toupper(key[plain[i] - 65]));
            }
            else
            {
                printf("%c", tolower(key[plain[i] - 97]));
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
