#include <stdio.h>
#include <math.h>

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
            float principal,period,fee,totalfee,rate,repayment;
            printf("[Option 2] Enter principal in dollars(positive), or -1 to end:\n");
            scanf("%f",&principal);
            if(principal==-1){
                selection=-1;
                break;
            }
            else if(principal<500){
                period=1;
                fee=0;
                rate=0;
            }
            else if(principal<1000){
                period=3;
                fee=20;
                rate=0.03;
            }
            else if(principal<2000){
                period=6;
                fee=17;
                rate=0.025;
            }
            else{
                period=12;
                fee=12;
                rate=0.015;
            }
            repayment=principal*pow(1.00+rate,period);
            totalfee=fee*period;
            printf("Principal: %.2f\n",principal);
            printf("Number of Period: %.0f\n",period);
            printf("Handling Fee per Period: %.2f\n",fee);
            printf("Insterest Rate per Period: %.2f\n",rate);
            printf("Repayment (Compound on Principal): %.2f\n",repayment);
            printf("Total Handling Fee: %.2f\n",totalfee);
            repayment=repayment+totalfee;
            printf("Total Repayment (including Handling Fee): %.2f\n",repayment);
            printf("Payment per Installment: %.2f\n",repayment/period);
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