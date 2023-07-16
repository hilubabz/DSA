#include<stdio.h>
#include<stdlib.h>

void merge(int A[],int low,int mid,int high){
	int l1, l2, k,i;
	l1=low;
	l2=mid;
	k=low;
	int B[10];
	while(l1<mid && l2<=high){
		if(A[l1]<A[l2]){
			B[k++]=A[l1];
			l1++;
		}
		else{
			B[k+1]=A[l2];
			l2++;
		}
	}
	while(l1<mid){
		B[k++]=A[l1];
		l1++;
	}
	while(l2<=high){
		B[k++]=A[l2];
		l2++;
	}
	for(i=low;i<=high;i++){
		A[i]=B[i];
	}
}
void mergesort(int A[],int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergesort(A,low,mid);
		mergesort(A,mid+1,high);
		merge(A,low,mid+1, high);
	}
}

int main(){
	int n,*A,i;
	printf("Enter number of elements :");
	scanf("%d",&n);
	
	A=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		printf("A[%d]=",i);
		scanf("%d",&A[i]);
	}
	printf("Before sorting :\n");
	for(i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
	mergesort(A,0,n-1);
	printf("\nAfter sorting :\n");
	for(i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
	free(A);
}
