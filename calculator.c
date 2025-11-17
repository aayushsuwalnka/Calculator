#include <stdio.h>
#include <math.h>
#include <string.h>
void add(double a[], int size);
void subtract(double a[], int size);
void multiply(double a[], int size);
void divide(double a[], int size);
void log_function(double a[], int size);
void sqrt_function(double a[], int size);
void power_function(double a[], int size);
void show_history();
char history[100][100];
int history_count = 0;
void add_to_history(const char *entry) 
{
    if (history_count < 100) {
        strncpy(history[history_count], entry, 99);
        history[history_count][99] = '\0';
        history_count++;
    }
}
int main() 
{
    int choice;
    double a[100];
    int size, i;
    printf("Enter the number of elements you want to use: ");
    scanf("%d", &size);
    printf("Enter the numbers:\n");
    for (i = 0; i < size; i++) {
        scanf("%lf", &a[i]);
    }
    do {
        printf("\nScientific Calculator\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Logarithm (log base 10)\n");
        printf("6. Square Root (sqrt)\n");
        printf("7. Power (x^n)\n");
        printf("8. Show History\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: add(a, size); break;
            case 2: subtract(a, size); break;
            case 3: multiply(a, size); break;
            case 4: divide(a, size); break;
            case 5: log_function(a, size); break;
            case 6: sqrt_function(a, size); break;
            case 7: power_function(a, size); break;
            case 8: show_history(); break;
            case 9: printf("Exiting the calculator. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    while (choice != 9);
    return 0;
}

void add(double a[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++) sum += a[i];
    printf("The sum is: %.2f\n", sum);
    char entry[100];
    snprintf(entry, sizeof(entry), "Sum: %.2f", sum);
    add_to_history(entry);
}

void subtract(double a[], int size)
{
    double diff = a[0];
    for (int i = 1; i < size; i++) diff -= a[i];
    printf("The result is: %.2f\n", diff);
    char entry[100];
    snprintf(entry, sizeof(entry), "Subtraction: %.2f", diff);
    add_to_history(entry);
}

void multiply(double a[], int size)
{
    double prod = 1;
    for (int i = 0; i < size; i++) prod *= a[i];
    printf("The product is: %.2f\n", prod);
    char entry[100];
    snprintf(entry, sizeof(entry), "Multiplication: %.2f", prod);
    add_to_history(entry);
}

void divide(double a[], int size)
{
    double result = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] == 0) {
            printf("Division by zero is undifined.\n");
            add_to_history("Division error: divide by zero");
            return;
        }
        result /= a[i];
    }
    printf("The result is: %.2f\n", result);
    char entry[100];
    snprintf(entry, sizeof(entry), "Division: %.2f", result);
    add_to_history(entry);
}

void log_function(double a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0) {
            double res = log10(a[i]);
            printf("log(%.2f) = %.2f\n", a[i], res);
            char entry[100];
            snprintf(entry, sizeof(entry), "log(%.2f) = %.2f", a[i], res);
            add_to_history(entry);
        } else {
            printf("Logarithm of negative values is undifined\n");
            add_to_history("Log error: nagative input");
        }
    }
}

void sqrt_function(double a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] >= 0) {
            double res = sqrt(a[i]);
            printf("sqrt(%.2f) = %.2f\n", a[i], res);
            char entry[100];
            snprintf(entry, sizeof(entry), "sqrt(%.2f) = %.2f", a[i], res);
            add_to_history(entry);
        } else {
            printf("negative number square root undifined\n");
            add_to_history("Sqrt error: negative input");
        }
    }
}

void power_function(double a[], int size)
{
    double exponent;
    printf("Enter the exponent: ");
    scanf("%lf", &exponent);
    for (int i = 0; i < size; i++)
    {
        double result = pow(a[i], exponent);
        printf("%.2f ^ %.2f = %.2f\n", a[i], exponent, result);
        char entry[100];
        snprintf(entry, sizeof(entry), "%.2f ^ %.2f = %.2f", a[i], exponent, result);
        add_to_history(entry);
    }
}

void show_history()
{
    printf("\n--- History ---\n");
    if (history_count == 0)
    {
        printf("Empty\n");
    } else
    {
        for (int i = 0; i < history_count; i++) {
            printf("%d. %s\n", i + 1, history[i]);
        }
    }
}