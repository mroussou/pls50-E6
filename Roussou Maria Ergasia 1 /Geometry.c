#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int x;
    float side, base_A, length, breadth, base_B, hypotenuse, Perimeter, radius;

    while(1){

        printf("-------------------------\n");

        printf(" 0 --> Exit\n");

        printf(" 1 --> Tetragono\n");

        printf(" 2 --> Parallilogrammo\n");

        printf(" 3 --> Orthogonio Trigono\n");

        printf(" 4 --> Kyklos\n");

        printf("-------------------------\n");

        printf("Epilexte ena apo ta akoloutha, dinontas to antistoixo arithmo\n");

        scanf("%d", &x);


        if (x == 0) {
            printf("Program Exits \n");
            exit(0);
        }
        if (x==1) {

            printf("Dwse to mhkos ths pleyras toy tetragwnou\n");

            scanf(" %f", &side);

            Perimeter = 4 * side;

            printf("H perimetros tou tetragwnou isoutai = %f\n", Perimeter);}


        if (x==2) {

            printf("Dwse to mhkos k to platos tou parallilogrammou\n");

            scanf(" %f %f", &breadth, &length);

            Perimeter = 2*breadth+ 2*length;

            printf("H perimetros tou parallilogrammou isoutai = %f\n", Perimeter);}


        if (x==3) {

            printf("Dwse to mhkos ton dyo basewn tou orthohoniou trigwnou\n");

            scanf(" %f %f", &base_A, &base_B );

            hypotenuse = sqrt(base_A * base_A + base_B * base_B);

            Perimeter = base_A + base_B + hypotenuse;

            printf("H perimetros tou trigonou isoutai = %f\n", Perimeter);}


        if (x==4) {

            printf("Dwse thn aktina tou kuklou\n");

            scanf(" %f", &radius);

            Perimeter = 2 * 3.14 * radius;

            printf("H perimetros tou kyklou isoutai = %f\n", Perimeter);}


    }
    return 0;
}
