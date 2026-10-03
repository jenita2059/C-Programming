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

    if (n == 0)
    {
        printf("\nNo expenses added yet.\n");
        return;
    }

    printf("\nExpense Details\n");

    for (i = 0; i < n; i++)
    {
        printf("\nExpense %d\n", i + 1);
        printf("Name: %s\n", expenses[i].name);
        printf("Category: %s\n", expenses[i].category);
        printf("Amount: %.2f\n", expenses[i].amount);
    }
}

void calculateTotal(struct Expense expenses[], int n)
{
    int i;
    float total = 0;

    for (i = 0; i < n; i++)
    {
        total = total + expenses[i].amount;
    }

    printf("\nTotal Expenses = %.2f\n", total);
}

void saveExpenses(struct Expense expenses[], int n)
{
    FILE *file;
    int i;

    file = fopen("expenses.txt", "w");

    for (i = 0; i < n; i++)
    {
        fprintf(file, "%s %s %.2f\n",
                expenses[i].name,
                expenses[i].category,
                expenses[i].amount);
    }

    fclose(file);

    printf("\nExpenses saved successfully!\n");
}

void loadExpenses(struct Expense expenses[], int *n)
{
    FILE *file;

    file = fopen("expenses.txt", "r");

    if (file == NULL)
        return;

    while (fscanf(file, "%s %s %f",
                  expenses[*n].name,
                  expenses[*n].category,
                  &expenses[*n].amount) == 3)
    {
        (*n)++;
    }

    fclose(file);
}

void deleteExpense(struct Expense expenses[], int *n)
{
    int number, i;

    if (*n == 0)
    {
        printf("\nNo expenses to delete.\n");
        return;
    }

    printf("\nEnter expense number to delete: ");
    scanf("%d", &number);

    if (number < 1 || number > *n)
    {
        printf("\nInvalid expense number.\n");
        return;
    }

    for (i = number - 1; i < *n - 1; i++)
    {
        expenses[i] = expenses[i + 1];
    }

    (*n)--;

    printf("\nExpense deleted successfully!\n");
}

int main()
{
    struct Expense expenses[100];
    int n = 0;
    int choice;

    loadExpenses(expenses, &n);

    while (1)
    {
        printf("\n===== EXPENSE TRACKER =====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total\n");
        printf("4. Save Expenses\n");
        printf("5. Delete Expense\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addExpense(expenses, &n);
                break;

            case 2:
                viewExpenses(expenses, n);
                break;

            case 3:
                calculateTotal(expenses, n);
                break;

            case 4:
                saveExpenses(expenses, n);
                break;

            case 5:
                deleteExpense(expenses, &n);
                break;

            case 6:
                printf("\nThank you for using Expense Tracker!\n");
                return 0;

            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
}
