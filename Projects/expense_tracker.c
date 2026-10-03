#include <stdio.h>

struct Expense
{
    char name[50];
    char category[30];
    float amount;
};

void addExpense(struct Expense expenses[], int *n)
{
    printf("\nEnter expense name: ");
    scanf("%s", expenses[*n].name);

    printf("Enter category: ");
    scanf("%s", expenses[*n].category);

    printf("Enter amount: ");
    scanf("%f", &expenses[*n].amount);

    (*n)++;

    printf("Expense added successfully!\n");
}

void viewExpenses(struct Expense expenses[], int n)
{
    int i;

    printf("\nExpense Details\n");

    for (i = 0; i < n; i++)
    {
        printf("\nExpense %d\n", i + 1);
        printf("Name: %s\n", expenses[i].name);
        printf("Category: %s\n", expenses[i].category);
        printf("Amount: %.2f\n", expenses[i].amount);
    }
}

int main()
{
    struct Expense expenses[100];
    int n = 0;

    addExpense(expenses, &n);
    viewExpenses(expenses, n);

    return 0;
}
