#include<stdio.h>
#include<stdlib.h>
#include<math.h>
static int count=0;
void merge(int b[],int c[],int a[],int p,int q){
	int i=0,j=0,k=0;
	while(i<p&&j<q){
		count++;
		if(b[i]<=c[j])
		a[k++]=b[i++];
		else
		a[k++]=c[j++];
	}
	while(i<p)
	a[k++]=b[i++];
	while(j<q){
		a[k++]=c[j++];
	}
}
void mergesort(int a[],float n){
	int *b,*c,i,p,q;
	if(n>1){
		p=floor(n/2);
		q=ceil(n/2);
		b=(int*)malloc(p*sizeof(int));
		c=(int*)malloc(q*sizeof(int));
		for(i=0;i<p;i++){
			b[i]=a[i];
		}
		for(i=p;i<n;i++)
		c[i-p]=a[i];
		mergesort(b,p);
		mergesort(c,q);
		merge(b,c,a,p,q);
	}
}
int main(){
	int n,*a,i;
	printf("enter the n\t");
	scanf("%d",&n);
	printf("array elements are \n");
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		a[i]=rand()%1001;
		printf("%d\t",a[i]);
	}
	mergesort(a,n);
	printf("sorted array ele \n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("basic opp count %d",count);
	
}
