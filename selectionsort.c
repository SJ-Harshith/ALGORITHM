#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int static count=0;
void swap(int *a,int *b){ *a^=*b; *b^=*a; *a^=*b;}
int selectionsort(int a[],int n){
    for(int i=0;i<n-1;i++){
           int pos=i;
          for(int j=i+1;j<n;j++){       //loop to find min element with its pos
           count++;
            if(a[pos]>a[j])              
                pos=j;
          }
          if(i!=pos){
            swap(&a[i],&a[pos]);       //swap min element pos with i;
          }
    }
    printf("sorted elements ");
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    printf("%d count ",count);
}
int main(){
    int *a,n;
    printf("enter the no of ele");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i]=rand()%5001;
        printf("%d\t",a[i]);
    }
    selectionsort(a,n);
}