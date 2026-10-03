#include <stdio.h>

int main()
{
    char str[100];
    char *p;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    p = str;

    printf("String: ");

    while (*p != '\0')
    {
        if (*p != '\n')
            printf("%c", *p);

        p++;
    }

    return 0;
}
