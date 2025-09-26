#include <stdio.h>
int main(void){
    int itotal=0,igrade=0,icounter=0;
    int igrademax=100;
    int igrademin=0;
    int ipass=0,ifail=0;
    float faverage;
    printf("Enter a grade between %d and %d for student%d, -1 to end:",igrademin,igrademax,icounter+1);
    scanf("%d", &igrade);
    while(igrade!=-1){
        if(igrade>=igrademin&&igrade<=igrademax){
            icounter=icounter+1;
            itotal=itotal+igrade;
            if(igrade>=60){
                ipass=ipass+1;
            }
            else{
                ifail=ifail+1;
            }
        }
        else{
            printf("The grade should be between %d and %d!\n",igrademin,igrademax);
        }
       

       printf("Enter a grade between %d and %d for student%d, -1 to end:",igrademin,igrademax,icounter+1);
       scanf("%d", &igrade); 
    }
    faverage=(float)itotal/icounter;
    if(icounter!=0){
        printf("%d passes\n",ipass);
        printf("%d fails\n",ifail);
        printf("The number of students is %d\n",icounter);
        printf("Class total grade is %d\n",itotal);
        printf("Class average grade is %.2f\n",faverage);

    }
    else{
        printf("No grades were entered\n");
    }
}