#include <stdio.h>

int main()
{
    char operator;
    float num1, num2, result=0;

    /*
     * Διαβάζει δύο αριθμούς κ ενα χαρακτήρα απο τον χρήστη
     */
    printf("Calculator\n");
    printf("----------------------------\n");
    printf("Dwse arithmo 1 [+ - * /] Dwse arithmo 2\n");

    /* Διαβάζει δύο αριθμούς απο τον χρήστη κ την πράξη */
    scanf("%f %c %f", &num1, &operator, &num2);

    switch(operator)
    {
        case '+': result = num1 + num2;
            break;
        case '-': result = num1 - num2;
            break;
        case '*': result = num1 * num2;
            break;
        case '/':
            num2 != 0 ? result = num1 / num2 : printf("Error! O diairetis einai miden 0");
            break;
        default: printf("Invalid Operator");
            return 0;

    }

    /* Εκτυπώνει το αποτέλεσμα */
    printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);

    return 0;
}
