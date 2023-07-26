#include<stdio.h>
#include<stdlib.h>

void swap(int *p, int *q){
	int a;
	a=*p;
	*p=*q;
	*q=a;
}
void heapify(int A[], int n, int i){
	int largest,lc,rc;
	largest=i;
	lc=2*i+1;
	rc=lc+1;
	if(lc<n && A[lc]>A[largest])
		largest=lc;
	if(rc<n && A[rc]>A[largest])
		largest=rc;
	if(largest!=i){
		swap(&A[i],&A[largest]);
		heapify(A,n,largest);
	}	
}

void heapsort(int A[], int n){
	int i;
	for(i=n/2-1;i>=0;i--){
		heapify(A,n,i);
	}
	for(i=n-1;i>=0;i--){
		swap(&A[0],&A[i]);
		heapify(A,i,0);
	}
}

int main(){
	int n,i;
	printf("Enter total number of elements :");
	scanf("%d",&n);
	int *A=(int*)malloc(n*sizeof(int));
	printf("Enter %d elements :\n",n);
	for(i=0;i<n;i++){
		printf("A[%d] :",i);
		scanf("%d",&A[i]);
	}
	heapsort(A,n);
	for(i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
	free(A);
	return 0;
}
