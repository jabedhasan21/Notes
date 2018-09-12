#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int A[], int n) {
    int i , j , temp, operationExecuted;
    operationExecuted = 0;
    for (i = 0; i < n; i++) {
        for (j = i+1; j >= 0; j--) {
            operationExecuted++;
            if( A[j-1] > A[j]) {
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
            }
        }
    }
    printf("\nAfter Sorted: ");
    for(i=0; i<n; i++) {
        printf(" %d ",A[i]);
    }
    printf("\nOperation Executed: %d",operationExecuted);
}

int main(int argc, char const *argv[])
{
    int A[20],i;
    srand(time(NULL));
    for (i = 0; i < 20; i++) {
        A[i] = rand() % 55;
    }

    printf("Before Sorted: ");;
    for (i = 0; i < 20; i++) {
        printf(" %d ",A[i]);
    }
    insertion_sort(A, 20);
    /*
    int tmp[] = {3,2,7,9,1,12,15,10,5,1};
    printf("Before Sorted: ");;
    for(i=0; i<10; i++) {
        printf(" %d ",tmp[i]);
    }
    insertion_sort(tmp, 10);
    */

    printf("\n");
    return 0;
}
