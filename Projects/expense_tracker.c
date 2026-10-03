#include <stdio.h>

struct Expense
{
    char name[50];
    char category[30];
    float amount;
};

int main()
{
    struct Expense expenses[100];
    int n, i;

    printf("Enter number of expenses: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter expense %d\n", i + 1);

        printf("Enter expense name: ");
        scanf("%s", expenses[i].name);

        printf("Enter category: ");
        scanf("%s", expenses[i].category);

        printf("Enter amount: ");
        scanf("%f", &expenses[i].amount);
    }

    printf("\nExpense Details\n");

    for (i = 0; i < n; i++)
    {
        printf("\nExpense %d\n", i + 1);
        printf("Name: %s\n", expenses[i].name);
        printf("Category: %s\n", expenses[i].category);
        printf("Amount: %.2f\n", expenses[i].amount);
    }

    return 0;
}
