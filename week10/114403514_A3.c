#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int choice;

void menu(void);//Function prototype 
void seperate_even_odd(int a[], int n, int even[], int odd[], int counts[]);
int sum_upper_triangle(int n, int a[][n]);

int main(void){
    srand(time(NULL));//initialize random seed
    do{
        menu();
        switch(choice){
            case 1: {
                int N;
                printf("\nEnter array size (1-20):");
                scanf("%d",&N);
                while(N<1||N>20){//validate input
                    printf("\nInvalid value! Try again!");
                    printf("\nEnter array size (1-20): ");
                    scanf("%d",&N);
                }
                int a[N],even[N],odd[N],counts[2];
                counts[0]=0;//count of even numbers
                counts[1]=0;//count of odd numbers
                for(int i = 0; i < N ; i++){//generate random value for the array
                    a[i]=rand()%11;
                }
                printf("\nOriginal array:\n");
                for(int i = 0; i < N; i++){//print original array
                    printf("%d ",a[i]);
                }
                seperate_even_odd(a,N,even,odd,counts);
                break;
            }
            case 2:{
                int N;
                printf("\nEnter matrix size N (1-5): ");
                scanf("%d",&N);
                while(N<1||N>5){
                    printf("\nInvalid value! Try again!");
                    printf("\nEnter matrix size N (1-5):");
                    scanf("%d",&N);
                }
                int matrix[N][N];
                for(int i = 0; i < N ; i++){
                    for(int j = 0; j < N; j++){
                        matrix[i][j]=rand()%51;
                    }
                }
                printf("\nOriginal 2D array (%dx%d) : \n",N,N);
                for(int i = 0; i < N ; i++){
                    for(int j = 0; j < N; j++){
                        printf("%-2d ",matrix[i][j]);
                    }
                    
                    printf("\n");
                }
                printf("Total sum of upper triangle elements: %d\n",sum_upper_triangle(N,matrix));
                break;
            
            }
            case -1:
                break;
            default://handle invalid input
                printf("Invalid option. Try again.\n");
                break;
        }
    }while(choice!=-1);
    printf("Program terminated\n");
}
void menu(void){ //display menu and get user choice
    printf("\n ==== MENU ==== \n");
    printf("1) Option 1 - Split into even and odd array\n");
    printf("2) Option 2 - Calculate Sum of Elements in the Upper Triangle\n");
    printf("(-1) End Program\n");
    printf("\nPlease select an option:");
    scanf("%d",&choice);
}

//split numbers into even and odd arrays
void seperate_even_odd(int a[], int n, int even[], int odd[], int counts[]){
    for(int i = 0; i < n ; i++){
        if(a[i]%2==0){
            even[counts[0]]=a[i];
            counts[0]+=1;//increase even counts
        }
        else{
            odd[counts[1]]=a[i];
            counts[1]+=1;//increase odd counts
        }
    }
    printf("\n\nTotal even numbers:%d\n",counts[0]);
    for(int i = 0; i < counts[0]; i++){
        printf("%d ",even[i]);
    }
    printf("\n\nTotal odd numbers:%d\n",counts[1]);
    for(int i = 0; i < counts[1]; i++){
        printf("%d ",odd[i]);
    }
}

//calculate the sum of upper triangle in the matrix
int sum_upper_triangle(int n, int a[][n]){
    int sum = 0;
    //j starts from i to n-1
    for(int i = 0; i < n; i++){
        for(int j = i; j < n ; j++){
            sum = sum + a[i][j];
        } 
    }
    return sum;
}