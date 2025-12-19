#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int choice;
void menu(void);// function prototype
void ring_traverse_recursive(int N, int A[][N],int top,int left,int bottom,int right);
void flatten_2d_to_1d(int N,int M[][N],int B[]);
void sort_ascending(int B[],int n);
void find_max_resourse_block(int N,int map[][N]);
int main(){
    srand(time(NULL));//initialize random seed
    do{
        menu();
        switch(choice){
            case 1: { //ring traversal
                int N;
                printf("\nPlease enter the size of the matrix (1-5):");
                scanf("%d",&N);
                if(N<1||N>5){//validate input
                    printf("\nInvalid input!\n");
                    break;
                }
                int matrix[N][N];
                for(int i = 0; i < N ; i++){//form matrix
                    for(int j = 0; j < N; j++){
                        matrix[i][j]=rand()%10;
                    }
                }
                printf("\n[Matrix A]\n");
                for(int i = 0; i < N ; i++){//print matrix
                    for(int j = 0; j < N; j++){
                        printf("%d ",matrix[i][j]);
                    }
                    printf("\n");
                }
                printf("\n[Ring traversal output]\n");
                ring_traverse_recursive(N,matrix,0,0,N-1,N-1);
                break;
            }
            case 2:{//flatten and sort
                int N;
                printf("\nPlease enter the size of the matrix (1-5):");
                scanf("%d",&N);
                if(N<1||N>5){//validate input
                    printf("\nInvalid input!\n");
                    break;
                }
                int B[N*N];
                int matrix[N][N];
                for(int i = 0; i < N ; i++){//form matrix
                    for(int j = 0; j < N; j++){
                        matrix[i][j]=rand()%100;
                    }
                }
                printf("\n[Matrix M (%d x %d)]\n",N,N);
                for(int i = 0; i < N ; i++){//print matrix
                    for(int j = 0; j < N; j++){
                        printf("%2d ",matrix[i][j]);
                    }
                    printf("\n");
                }
                flatten_2d_to_1d(N,matrix,B);
                printf("\n[Flatten 1D array B in row-major order]\n");
                for(int i = 0; i < N*N; i++){
                    printf("%d ",B[i]);
                }
                printf("\n\n[Sorted 1D array B (ascending)]\n");
                sort_ascending(B,N*N);
                break;
            
            }
            case 3:{
                int N;
                printf("\nPlease enter the size of the matrix (3-10):");
                scanf("%d",&N);
                if(N<3||N>10){//validate input
                    printf("\nInvalid input!\n");
                    break;
                }
                int matrix[N][N];
                for(int i = 0; i < N ; i++){//form matrix
                    for(int j = 0; j < N; j++){
                        matrix[i][j]=rand()%10;
                    }
                }
                printf("\n[Matrix M (%d x %d)]\n",N,N);
                for(int i = 0; i < N ; i++){//print matrix
                    for(int j = 0; j < N; j++){
                        printf("%-2d ",matrix[i][j]);
                    }
                    printf("\n");
                }
                find_max_resourse_block(N,matrix);

            }
            case -1:
                break;
            default://handle invalid input
                printf("Invalid option. Try again.\n");
                break;
        }
    }while(choice!=-1);
    printf("Program ends\n");

}

void menu(void){ //display menu and get user choice
    printf(" ==== MENU ==== \n");
    printf("1) Option 1 - Ring Traversal of a Square Matrix\n");
    printf("2) Option 2 - Flatten and Sort\n");
    printf("3) Option 3 - Maximum Resource Block Finder\n");
    printf("-1) End Program\n");
    printf("Select:");
    scanf("%d",&choice);
}

void ring_traverse_recursive(int N, int A[][N],int top,int left,int bottom,int right){
    int count=0;
    for (int j = left;j <= right; j++){//go right
        printf("%d ",A[top][j]);
        count++;
    }
    top++;
    for(int i = top; i <= bottom; i++){//go down
        printf("%d ",A[i][right]);
        count++;
    }
    right--;
    for(int j = right; j >=left; j--){//go left
        printf("%d ",A[bottom][j]);
        count++;
    }
    bottom--;
    for(int i = bottom; i >= top; i--){//go up
        printf("%d ",A[i][left]);
        count++;
    }
    left++;
    if (count==1||count==4){//base case (If N is odd, count is 1; otherwise count is 4)
        printf("\n");
    }
    else{
        ring_traverse_recursive(N,A,top,left,bottom,right);
    }
    
}

void flatten_2d_to_1d(int N,int M[][N],int B[]){
    int count;
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            B[count]=M[i][j];
            count++;
        }
    }
}
void sort_ascending(int B[],int n){//bubble sort
    int temp;
    for(int i = 0; i < n; i++){
        if(B[i] > B[i+1]){//swap
            temp = B[i];
            B[i] = B[i+1];
            B[i+1] = temp;
            i=-1;
        }
    }
    for(int i = 0; i < n; i++){//print the sorted array
                    printf("%d ",B[i]);
                }
                printf("\n");

}

void find_max_resourse_block(int N,int map[][N]){
    int max=-1,maxi=0,maxj=0,sum;//cpi=current position i; cpj=current position j 
    for(int cpi = 0; cpi < N-2 ; cpi++){
        for(int cpj = 0; cpj < N-2; cpj++){
            sum = 0;
            for(int i = 0; i < 3;i++){//caluculate sum of block resourse
                for(int j = 0; j < 3; j++){
                    sum = sum + map[cpi+i][cpj+j];
                }
            }
            if(sum>max){// record the max sum and the left coordinate of the block
                max = sum;
                maxi = cpi;
                maxj = cpj;
            }

        }
    }
    printf("\n\nMaximum resourse sum: %d\n",max);
    printf("Top-left coordinate: (%d,%d)\n",maxi,maxj);
    printf("Max resourse block:\n");
    for(int i = 0; i < 3;i++){// print the block
                for(int j = 0; j < 3; j++){
                    printf("%d ",map[maxi+i][maxj+j]);
                }
                printf("\n");
            }


}