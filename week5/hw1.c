#include <stdio.h>

int main(void){
    int balance=10000,amount;
    printf("Balance setting:%d\n",balance);
    printf("Current balance:%d\n",balance);
    printf("\nEnter withdrawal amount (0 to quit)\n");
    scanf("%d",&amount);
    while(amount!=0){ //判斷是否要結束交易
        if (amount<0){
            printf("Invalid input, please try again.\n"); //無效輸入：數值小於0
           
        }
        else if(amount%100!=0){ //數值非一百的倍數
            printf("Withdrawal amount must be a multiple of 100\n");
            printf("Current balance:%d\n",balance);
        }
        else if(amount>balance){ //數值大於目前帳戶餘額
            printf("Insufficient balance.\n");
            printf("Current balance:%d\n",balance);
        }
        else{ 
            balance=balance-amount;
            printf("Withdrawal successful!\n");
            printf("Current balance:%d\n",balance);
        }
        printf("\nEnter withdrawal amount (0 to quit)\n");
        scanf("%d",&amount);
    }
    printf("Transaction ended\n");
    printf("Final balance:%d\n",balance);

} //end main