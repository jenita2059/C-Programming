#include <stdio.h>

int main()
{
    FILE *file;

    file = fopen("data.txt", "w");

    fprintf(file, "Hello from my C program!");

    fclose(file);

    printf("Data written successfully.");

    return 0;
}
