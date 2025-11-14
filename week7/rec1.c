#include<stdio.h>
void print_number(int n){
    if(n==0){ //base case
        printf("\n");
        return;
    }
    else{ //recursive step
        printf("%d",n);
        print_number(n-1);
    }
}

int main(void){
    int n,check=0;
    printf("Please enter an integer between 1 and 9.\n");
    scanf("%d",&n);
    if(n>=1&&n<=9){ //valid input
        check=1;
    }
    while(check!=1){ //handle invalid input
        printf("Invalid input! Try again.\n");
        printf("Please enter an integer between 1 and 9.\n");
        scanf("%d",&n);
        if(n>=1&&n<=9){ //valid input
        check=1;
    }
    }
    print_number(n);
}