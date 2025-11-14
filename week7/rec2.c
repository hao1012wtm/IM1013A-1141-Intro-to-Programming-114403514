#include <stdio.h>
int sum_of_digits(int n,int s){
    if(n<10){ //base case
        return n+s;
    }
    else{ //recursive step
        s = s + n%10;
        n = (n - n%10) / 10;
        return sum_of_digits(n,s);
    }
}
int main(void){
    int n;
    printf("Please enter an integer between 1 and 100000.\n");
    while(1){ //check if the input is valid
        scanf("%d",&n);
        if(n >= 1 && n <= 100000){//valid input
            break;
        }
        printf("Invalid input! Try again.\n");//handle invalid input
        printf("Please enter an integer between 1 and 100000.\n");
    }
    printf("The sum of digits of %d is %d.\n",n,sum_of_digits(n,0));
}