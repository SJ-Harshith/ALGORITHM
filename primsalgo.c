#include<stdio.h>
#include<stdlib.h>
void prims(int n,int s,int cost[][10]){
	int i,j,a,b,min,totalcost=0,edge_count=0;
	int tree_vertex[10]={0};
	tree_vertex[s]=1;
	while(edge_count<n-1){
		min=999;
		for(i=0;i<n;i++){
			if(tree_vertex[i]==1){
				for(j=0;j<n;j++){
					if(tree_vertex[j]==0&&cost[i][j]<min){
						min=cost[i][j];
						a=i;
						b=j;
					}
				}
			}
		}
		printf("Edge from vertices %d to %d in %d\n",a,b,min);
		tree_vertex[b]=1;
		totalcost+=min;
		edge_count++;
	}
	printf("min cost =%d\n",totalcost);
}
int main(){
	int n,s,i,j;
		int cost[10][10];
	printf("enter the no of vertices: ");
	scanf("%d",&n);

	printf("enter  the cost matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				scanf("%d",&cost[i][j]);
		}
	}
	printf("enter the source vertex: ");
	scanf("%d",&s);
	prims(n,s,cost);
}
