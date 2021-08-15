#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *cipher_tolower(char *str)
{
    int i;
    char c;

    i = 0;
    while (str[i] != '\0')
    {
        c = str[i];
        if (isalpha(c))
        {
            str[i] = tolower(c);
        }
        else
        {
            return ("");
        }
        i++;
    }
    return (str);
}

int cipher_validation(char *str)
{
    int i;
    int j;

    i = 0;
    while (i < 25)
    {
        j = i + 1;
        while (j < 25)
        {
            if (str[i] == str[j])
            {
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

char *substitution(char *str, char *cipher)
{
    int i;
    int i_cipher;
    char c;
    int offset;

    i = 0;
    offset = 0;
    // converts alpha letters in str for subs
    while (str[i] != '\0')
    {
        c = str[i];
        if (isupper(c))
        {
            offset = 32;
        }
        if (isalpha(c))
        {
            i_cipher = tolower(c) - 'a';
            str[i] = cipher[i_cipher] - offset;
        }
        offset = 0;
        i++;
    }
    return (str);
}

int main(int argc, char *argv[])
{
    char *str;
    int is_valid;

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }
    argv[1] = cipher_tolower(argv[1]);
    is_valid = cipher_validation(argv[1]);
    if (ft_strlen(argv[1]) != 26 || is_valid == 0)
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
    str = get_string("plaintext: ");
    str = substitution(str, argv[1]);
    printf("ciphertext: %s\n", str);
    return (0);
}