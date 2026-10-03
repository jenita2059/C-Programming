#include <stdio.h>

int main()
{
    FILE *file;
    char text[100];

    file = fopen("data.txt", "r");

    fgets(text, sizeof(text), file);

    printf("Data from file: %s", text);

    fclose(file);

    return 0;
}
