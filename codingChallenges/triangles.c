#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Prototypes of helper-functions
bool isTriangle(int a, int b, int c);
char categorizeTriangle(int a, int b, int c);

int main(int argc, char* argv[])
{
    // Variables for the lengths of the triangel's sides.
    int a, b, c;

    // IF | If not give correct command-line arguments
    if (argc != 4)
    {
        printf("Please enter the lengths of the sides.\n");

        printf("A: ");
        scanf("%i", &a);

        printf("B: ");
        scanf("%i", &b);

        printf("C: ");
        scanf("%i", &c);
    }
    // ELSE | Given correct command-line arguments
    else
    {
        // atoi converts string to integer.
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
    }

    if (isTriangle(a, b, c))
    {
        // Get type of triangle; and print the type.
        char type = categorizeTriangle(a, b, c);
        if (type == 'e')
            printf("Equilateral triangle.\n");
        else if (type == 's')
            printf("Scalene triangle.\n");
        else
            printf("Isosceles triangle.\n");
    }
    else
    {
        printf("It's NOT a triangle\n");
    }

    return 0;
}

bool isTriangle(int a, int b, int c)
{
    // No lenght can be greater than,
    // or equal to, the other sides combined.
    if (a >= b + c || b >= a + c || c >= a + b)
        return false;
    return true;
}

char categorizeTriangle(int a, int b, int c)
{
    // Equilateral | All sides are equal in length.
    if (a == b && b == c)
        return 'e';
    // Scalene | All sides have different lengths.
    else if (a != b && b != c && c != a)
        return 's';
    // Isosceles | Two sides are equal in length.
    else
        return 'i';
}
