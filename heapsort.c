#include<stdio.h>
#include<stdlib.h>
void bottomup(int n,int h[]){
	int i,k,v,heap,j;
	for(i=(floor(n/2));i=>1;i--){
		k=i;          //get ith index
		v=h[k];        //get the ith element and store in v
		heap=0;        //heap is false take it as 0 1 when true
		while(heap==1&& 2*k<=n){  //if array not heapified and its child node<=n
			j=2*k;              //get the left child index
			if(j<n){            //if it has 2 child nodes then 
			  if(k<h[j+1]){
			      j=j+1;        //compare the child nodes and get max child index
			}
		   }
		if(v>=h[j]){
		heap=1;             //if it is already heapified make heap as true
	     }
	     else{
	     	h[k]=h[j];
	     	k=j;
		 }
          }
h[k]=v;
    }
}
void heapsort(int n,int h[]){
	int i,temp;
	bottomup(n,h);   //heapify
	for(i=n;i>1;i--){
	  temp=h[i];
	  h[i]=h[1];
	  h[1]=temp;      //swap(last ele and first element)
	  bottomup(i-1,h);       //heapify for n-1 
	}
}

int main(){
	int i,n,h[10];
	printf("enter the number of elemnts\n");
	scanf("%d",&n);
	printf("enter the array elements\n");
	for(i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	heapsort(n,h);
	printf("after heapsort\n");
	for(i=1;i<=n;i++){
		printf("%d",h[i]);
	}
}
