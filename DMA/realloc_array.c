#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, new_n, i;
    int *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d numbers: ", n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter new size: ");
    scanf("%d", &new_n);

    arr = (int *)realloc(arr, new_n * sizeof(int));

    printf("Enter additional numbers: ");

    for (i = n; i < new_n; i++)
        scanf("%d", &arr[i]);

    printf("Array elements: ");

    for (i = 0; i < new_n; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}
