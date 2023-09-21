// EXAMPLE: switch statement

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float value_a = 4;
    float value_b = 10;

    char op = '/';

    switch(op)
    {
        case '/':
            puts("Division!");
            printf("%f\n", value_a / value_b);
            break;

        case '+':
            puts("Addition!");
            // break; // NOTE: If we don't put a break, code will "fall through" the next case statement.
                      // So here we'll (incorrectly) print "Substraction!" as well.      

        case '-':
            puts("Substraction!");
            break;

        // if there are multiple case xxx: statements, both of them will execute the code below (until break;)
        case '*':
        case 'x':
            puts("Multiplication!");
            break;

        case 'C':
            if (a < 0) { // a second condition must be in a separate if statement, you
                         //can't add extra conditions to the case itself.
                
            }

    }

    return EXIT_SUCCESS;
}

