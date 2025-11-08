#include <stdio.h>
int choice;

int multiplication(int a,int b){ //compute a times b
    return(a*b);
}

void reverse_number(int a){ //reverse the number
    printf("--- REVERSAL RESULT ---\n");
    printf("Original number N: %d\n",a);
    printf("Reversed number R: ");
    while(a!=0){
        printf("%d",a%10);//print units digit
        a=(a-a%10)/10;// remove units digit
    }
    printf("\n");
}

void menu(void){ //print menu and input choice
    printf("\n ==== MENU ==== \n");
    printf("1) Option 1 - times table\n");
    printf("2) Option 2 - reverse the number\n");
    printf("(-1) End Program\n");
    printf("\nPlease select an option:");
    scanf("%d",&choice);
}

void table(void){//print multiplication table 
    int multiplicand,multiplier,product;
    printf("\n");
    for (multiplicand = 1; multiplicand <= 9; multiplicand++) { 
        for (multiplier = 1; multiplier <= 9; multiplier++) {  
            product=multiplication(multiplicand,multiplier);
            printf("%2d *%2d = %2d ",multiplicand,multiplier,product);
        }
        printf("\n");  
    }

}

int main(void){
    menu();
    do{switch(choice){
            case 1: 
                table();
                menu();
                break;
            case 2:{
                int num;
                printf("Enter a positive integer between 1 and 100000\n");
                scanf("%d",&num);
                while(num<1||num>100000){ 
                    printf("Invalid input!\n");
                    printf("Enter a positive integer between 1 and 100000\n");
                    scanf("%d",&num);
                }
                reverse_number(num);
            }
                menu();
                break;
            case -1:
                break;
            default:
                printf("Invalid option. Try again.\n");
                menu();
                break;
        }
    }while(choice!=-1);
    printf("Program terminated\n");
}
