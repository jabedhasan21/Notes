#include <stdio.h>
#include <stdlib.h>

void selection_sort(int A[], int n){
	int i, j, index_min,temp;
	for( i=0; i<n; i++ ){
		index_min = i;
		for( j = i+1; j<n; j++ ){
			if(A[index_min] > A[j]){
				index_min = j;
			}
		}
		if(index_min != i){
			temp = A[index_min];
			A[index_min] = A[i];
			A[i] = temp;
		}
	}
	printf("\nAfter Sorting Values\n");
	for( i=0;i<n;i++){
	 printf("%d ", A[i]);
	}
}
int main(void) {
	int i, A[10];
	for(i=0; i<10; i++){
		A[i] = rand() % 50;
	}
	printf("Initital Values\n");
	for( i=0;i<10;i++){
	 printf("%d ", A[i]);
	}
	selection_sort(A,10);
	return 0;
}
