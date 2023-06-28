#include<stdio.h>
int i=1;
void TOH(int n, char A, char B, char C){
    if(n>0){
        TOH(n-1,A,C,B);
        printf("%d. Move %d disk from %c to %c\n",i++,n,A,C);
        TOH(n-1,B,A,C);
    }
}

int main(){
    int n;
    printf("Enter no of disks :");
    scanf("%d", &n);
    TOH(n,'A','B','C');
    return 0;
}
