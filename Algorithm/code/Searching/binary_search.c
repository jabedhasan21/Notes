#include <stdio.h>
#include <stdlib.h>

int binary_search(int A[], int n, int x) {
    int left, right, mid;
    left = 0;
    right = n - 1;

    while(left <= right) {
        mid = (left + right)/2;
        if(A[mid] == x){
            return mid;
        }
        if(A[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void)
{
    /* code */
    int i, A[20], x;
    for(i=0; i<20; i++) {
        A[i] = (i+1)*(i+1);
    }
    printf("\nValues...: ");
    for(i=0;i<20; i++){
        printf("%d ",A[i]);
    }
    printf("\nSearching for: ");
    scanf("%d",&x);
    printf("Found in index: %d\n", binary_search(A,20,x));
    return 0;
}