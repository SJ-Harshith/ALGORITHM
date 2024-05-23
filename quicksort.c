#include<stdio.h>
#include<stdlib.h>
int count=0;
int partition(int a[],int l,int r){
	int pivot=a[l],i=l,j=r+1,temp;
	do{
     	do{
		i++;
		count++;
	    }while(i<r&&a[i]<pivot);
      	do{
		j--;
		count++;
     	}while(j>l&&a[j]>pivot);
	    if(i<j){
		    temp=a[i];
	     	a[i]=a[j];
		    a[j]=temp;
	    }
    }while(i<j);
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
}
void quicksort(int a[],int l,int r){
	int s;
	if(l<r){
		s=partition(a,l,r);
		quicksort(a,l,s-1);
		quicksort(a,s+1,r);
	}
}
int main(){
	int *a,n,i;
	printf(" enter the n:");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("array elements are \n");
	for(i=0;i<n;i++){
		a[i]=rand()%1001;
		printf("%d\t",a[i]);
	}
	quicksort(a,0,n-1);
	printf("sorted array elemts are \n");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	printf("basic opp count %d ",count);
	}
