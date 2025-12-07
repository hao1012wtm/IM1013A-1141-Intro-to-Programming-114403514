#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define SIZE 5

void initializeArray(int size, int array[size]){
    for(int i = 0; i < size ; i++){
        array[i]=1;
    }
}
void printArray(int size, int array[size]){
    printf("iArray = {");
    for(int i = 0; i < size ; i++){
        printf("%d",array[i]);
        if(i!=size-1){
            printf(",");
        }
    }
    printf("}\n");

}
void randomizeArray(int size, int array[size]){
    srand(time(NULL));
    for(int i = 0; i < size ; i++){
        array[i]= rand()%10;
    }
}
int sumOfArrayElements(int size, int array[size]){
    int sum=0;
    for(int i =0; i < size; i++){
        sum+=array[i];
    }
    return sum;
}

int main(void){
    int iArray[SIZE];

    unsigned int isize = 0;
    puts("enter array size");
    scanf("%u",&isize);
    int iMyArray[isize];
    puts("uninitialized array");
    printArray(isize,iMyArray);
    initializeArray(isize,iMyArray);
    puts("initialized array");
    printArray(isize,iMyArray);
    randomizeArray(isize,iMyArray);
    puts("randomized array");
    printArray(isize,iMyArray);
    printf("The sum of array elements is %d\n",sumOfArrayElements(isize,iMyArray));

}
