#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int A[], int n) {
    int i, j, temp, counter;
    counter = 0;
    for( i=0; i<n; i++) {
        for(j=0; j<n-i-1; j++) {
            counter++;
            if(A[j] > A[j+1]) {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    printf("\nSorted Values: ");
    for(i=0; i<n; i++) {
        printf(" %d", A[i]);
    }

    printf("\nCount: %d\n",counter);
}

int main(int argc, char const *argv[])
{
    /* code */

    int i, A[30];
    for(i=0; i<30; i++) {
        A[i] = rand() % 88;
    }

    printf("Initial Values: ");
    for(i=0; i<30; i++) {
        printf(" %d",A[i]);
    }
    bubble_sort(A,30);

    return 0;
}
