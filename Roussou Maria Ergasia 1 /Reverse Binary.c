#include <stdio.h>

int main(){
int inputnum = -5;
int wronginputflag = 0;
int const two = 2;
int tmp = -5;
/*diavase enan arithmo*/
do{
wronginputflag == 0 ?  printf("Dose enan thetiko akeraio arithmo") :  printf("wrong input. Ksanadose arithmo");
putchar('\t');
scanf("%d", &inputnum);
wronginputflag = 1;
}while(inputnum <= 0);


while( inputnum > 0){
tmp = inputnum%two;
tmp==1? putchar('1') : putchar('0');
inputnum = inputnum/two;
}
putchar('\n');
printf("bye!");
putchar('\n');
return 0;

}
