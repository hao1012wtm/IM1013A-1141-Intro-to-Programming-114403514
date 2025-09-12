# include <stdio.h>

int main(void){
    float numc,numf;
    printf("Enter the temparature in Celsius\n");
    scanf("%f",&numc);
    numf=numc*9/5+32;
    printf("The temparature in Fahrenheit is %f\n",numf);
}
//end main