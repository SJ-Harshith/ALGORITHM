#include<stdio.h>
#include<stdlib.h>
void kruskal(int cost[][10],int n){
	int i,j,parentarray[n],ecount,min,a,b,u,v,mincost=0;
	for(i=0;i<n;i++){
		parentarray[i]=-1;  //intialize parentarray =-1
	}
	ecount=0;             //edgecounter
	while(ecount<n-1){
		 min=999;
		 for(i=0;i<n;i++){
		 	for(j=0;j<n;j++){
		 		if(cost[i][j]<min){
		 			min=cost[i][j];
		 			a=u=i;
		 			b=v=j;
				 }
			 }
		 }
		 while(parentarray[u]!=-1)
		 		u=parentarray[u];
		while(parentarray[v]!=-1)
				v=parentarray[v];
		if(u!=v){
			printf("\nedge from %d to %d with cost %d is selected",a,b,min);
			parentarray[b]=a;
			mincost+=min;
			ecount++;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("min cost is %d",mincost);
}
int main(){
	int i,n,j,cost[10][10];
	printf("enter the no of vertices\n");
	scanf("%d",&n);
	printf("enter the cost matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	kruskal(cost,n);
}
