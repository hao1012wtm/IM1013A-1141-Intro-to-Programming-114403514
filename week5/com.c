#include <stdio.h>
#include <math.h>

int main(void){
    float p,r,a;
    int n;
    printf("Please enter the principal\n");
    scanf("%f",&p);
    printf("Please enter the annual interest rate\n");
    scanf("%f",&r);
    r=r/100;
    printf("Please enter the number of years\n");
    scanf("%d",&n);
    printf("%4s%21s\n","Years", "Amount on deposit");
    for(int year=1; year <= n; year++){
        a=p*pow(1.0 + r, year);
        printf("%4u%21.2f\n",year,a);
    }



}//end main