#include <stdio.h>
#include <stdlib.h>

int linear_search(int a[], int n, int x){
    int i;
    for(i=0; i<n; i++){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int i, a[10], x;
    for(i=0; i<10; i++){
        a[i] = rand() % 88;
    }
    printf("Values: ");
    for(i=0; i<10; i++){
        printf("%d ",a[i]);
    }
    printf("\nLooking for : ");
    scanf(" %d",&x);
    printf("\nFound in index: %d\n", linear_search(a,10,x));
    return 0;
}
