#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int A[], int n) {
    int i, j, item, operationExecuted;
    operationExecuted = 0;
    for (i = 1; i < n; i++) {
        item = A[i];

        j = i - 1;
        while (j >= 0 && A[j] > item ) {
            A[j+1] = A[j];
            j = j - 1;
            operationExecuted++;
        }
        A[j+1] = item;
    }
    printf("\nAfter Sorted: ");;
    for (i = 0; i < n; i++) {
        printf(" %d ",A[i]);
    }
    printf("\nOperation Executed: %d", operationExecuted);
}
int main(void)
{
    int A[20],i;
    srand(time(NULL));
    for(i=0; i<20; i++) {
        A[i] = rand() % 55;
    }

    printf("Before Sorted: ");;
    for(i=0; i<20; i++) {
        printf(" %d ",A[i]);
    }
    /*
    int tmp[] = {3,2,7,9,1,12,15,10,5,1};
    printf("Before Sorted: ");;
    for(i=0; i<10; i++) {
        printf(" %d ",tmp[i]);
    }
    insertion_sort(tmp, 10);
    */
    insertion_sort(A, 20);
    printf("\n");
    return 0;
}