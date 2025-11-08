#include <stdio.h>
int main(void){
    int row,col;
    printf("Enter row size.");
    scanf("%d",&row);
    printf("Enter column size.");
    scanf("%d",&col);
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            printf("* ");
        }
        printf("\n");
    }
}