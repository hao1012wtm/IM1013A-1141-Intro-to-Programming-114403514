# include <stdio.h>

int main(void){
    float tempc,tempf;
    printf("Please enter the temparature in Celsius\n");
    scanf("%f",&tempc);
    tempf=tempc*9/5+32;
    printf("The temparature in Fahrenheit is %f\n",tempf);
}
//end main