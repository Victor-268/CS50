#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1 || argc == 3)
    {
        return 1;
    }

    string key = argv[1];
    char used[26];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must be alphabetic\n");
            return 1;
        }

        for (int j = 0; j < i; j++)
        {
            if (key[i] == used[j])
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
        used[i] = key[i];
    }

    string text = get_string("plaintext: ");

    for (int h = 0; h < strlen(text); h++)
    {
        if (isalpha(text[h]))
        {
            char base = isupper(text[h]) ? 'A' : 'a';
            text[h] = isupper(text[h]) ? toupper(key[text[h] - base]) : tolower(key[text[h] - base]);
        }
        else if (text[h] == ' ')
        {
            continue;
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
