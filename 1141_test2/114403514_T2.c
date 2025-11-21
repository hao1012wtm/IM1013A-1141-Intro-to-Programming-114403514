#include <stdio.h>
int selection,bin[7],count_array; //bin[] is an array to save remainder for option 2
void menu(void){ //print the menu and input selection
    printf(" ==== MENU ==== \n");
    printf("1) Option 1 - Increasing Number Triangle Pattern\n");
    printf("2) Option 2 - Decimal to binary number using recursion\n");
    printf("3) Option 3 - Printing a Four-Quadrant Pattern\n");
    printf("-1) End Program\n");
    printf("Select:");
    scanf("%d",&selection);
}
void triangle(void){ //option 1 : print the triangle pattern
    int N,count_num=1,count_row=1;
    printf("\nPlease enter the size of the triangle (1~20)\n");
    scanf("%d",&N);
    if(N>=1&&N<=20){ //check if the input is valid
        for(int r=1;r<=N;r++){
            for (int c=1;c<=count_row;c++){
                printf("%d ",count_num);
                count_num++;
            }
            count_row++;
            printf("\n");
        }

    }
    else{
        printf("Invalid input!\n\n");
    }

}
void dectobin(int N){
    bin[count_array]=N%2;// save the remainder 
    if(N/2==0){ //base case
        for (int i=count_array;i>=0;i--){// print the reversal of saved remainders
            printf("%d", bin[i]);
        }
        printf("\n");
        return;
    }
    else{
        N=N/2;
        count_array++;
        dectobin(N);
    }

}
void binary(void){ // option 2 : decimal to binary
    int N;
    printf("\nPlease enter a decimal number (0~127)\n");
    scanf("%d",&N);
    if(N>=0&&N<=127){ //check if the input is valid
        count_array=0;
        dectobin(N);
    }
    else{
        printf("Invalid input!\n\n");
    }
}
void get_symbol(int row,int col,int N){ //decide which symbol to print
    if(row == N+1){
        if(col == N+1){
            printf("+");
        }
        else{
            printf("-");
        }
    }
    else if(col == N+1){
        printf("|");
    }
    else if(row <= N){
        if(col <= N){
            printf("@");
        }
        else{
            printf("#");
        }
    }
    else{
        if(col <= N){
            printf("%%");
        }
        else{
            printf("&");
        }

    }
}
void quadrant(void){// option 3 : print the four-quadrant pattern
    int N;
    printf("\nPlease enter the size of each quadrant\n");
    scanf("%d",&N);
    for(int r=1;r<=N*2+1;r++){
        for(int c=1;c<=N*2+1;c++){
            get_symbol(r,c,N);
        }
        printf("\n");
    }

}
int main(void){
    do{
        menu();
        switch(selection){ 
            case 1:
            triangle();
            break;
            case 2:
            binary();
            break;
            case 3:
            quadrant();
            break;
            case -1:
            break;
            default:
            printf("\nInvalid menu option. Try again.\n\n");
            break;
        }
    }while(selection!=-1);
    printf("\nProgram Ended\n");
}