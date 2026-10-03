#include <stdio.h>

struct Expense
{
    char name[50];
    char category[30];
    float amount;
};

int main()
{
    struct Expense e;

    printf("Enter expense name: ");
    scanf("%s", e.name);

    printf("Enter category: ");
    scanf("%s", e.category);

    printf("Enter amount: ");
    scanf("%f", &e.amount);

    printf("\nExpense Details\n");
    printf("Name: %s\n", e.name);
    printf("Category: %s\n", e.category);
    printf("Amount: %.2f", e.amount);

    return 0;
}
