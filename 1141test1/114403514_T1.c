#include <stdio.h>
int main (void){
    int selection;
    printf("==== Future City Expo Ticket System ====\n");
    printf("1) Option 1 - Single-Order Quotation\n");
    printf("2) Option 2 - Group Total & Installments\n");
    printf("(-1) End Program\n");
    scanf("%d",&selection);
    if(selection==-1){
        printf("Select: %d\n",selection);
    }
    while(selection!=-1){
        if(selection==1){
            int adult,student,ticket;
            float factor1,factor2,total;
            printf("[Option 1] Enter the number of adults (1-20), or -1 to end:\n");
            scanf("%d",&adult);
            if(adult==-1){
                selection=-1;
                break;
            }
            printf("[Option 1] Enter the number of students (1-20), or -1 to end:\n");
            scanf("%d",&student);
            if(student==-1){
                selection=-1;
                break;
            }
            ticket=adult+student;
            if(ticket<=5){
                factor1=1.00;
            }
            else if(ticket<=10){
                factor1=0.95;
            }
            else if (ticket<=15){
                factor1=0.90;
            }
            else{
                factor1=0.85;
            }
            if(ticket%5==0){
                factor2=0.95;
            }
            else{
                factor2=1.00;
            }
            total=adult*200+student*150;
            printf("--- Quotation Summary ---\n");
            printf("Adults: %d, Students: %d, Total Tickets: %d\n",adult,student,ticket);
            printf("Base Total:  %.2f\n",total);
            printf("Quantity Discount Factor: %.2f\n",factor1);
            if(factor2==0.95){
                printf("Multiple-Of-5 Bonus Applied: YES (Factor: %.2f)\n",factor2);
            }
            else{
                printf("Multiple-Of-5 Bonus Applied: NO (Factor: %.2f)\n",factor2);
            }
            total=total*factor1*factor2;
            printf("Finale Payable Amount: %.2f\n",total);
        }
        else if (selection==2){
            continue;

        }
        else{
            printf("Select: %d\n",selection);
            printf("Unknown selection. Please choose 1, 2, or -1 to end.\n");
            printf("==== Future City Expo Ticket System ====\n");
            printf("1) Option 1 - Single-Order Quotation\n");
            printf("2) Option 2 - Group Total & Installments\n");
            printf("(-1) End Program\n");
            scanf("%d",&selection);
        }
    }
    printf("Program ends.\n");//end main
}