#include<stdio.h>
void shortest(int n,int c[][10],int s){
	int i,d[10],visited[10],count,min,u,v;
	for(i=0;i<n;i++){
		d[i]=c[s][i];       //get 1 st row of cost copied to distance matrix 
		visited[i]=0;             //intialize visitedistied array to 0 that intially no visitedertex has been visitedisited
	}
	d[s]=0;              //distance of source to source is always 0
	visited[s]=1;              //source has been visitedisited
	for(count=0;count<n-1;count++){
		min=999;
		for(i=0;i<n;i++){
			if(visited[i]==0&&d[i]<min){    //if the  visitedertex has not been visitedisited and its distance is min
				min=d[i];              //get it has min dist
				u=i;                   // u is used to track the min distance visitedertex index 
			}
		}
		visited[u]=1;               //visied has to be updated
		for(v=0;v<n;v++){
			if(visited[v]==0&&c[u][v]!=999&&d[v]>d[u]+c[u][v]){
				d[v]=d[u]+c[u][v];                 //to update the distance array when its dist is min and not visited and not adjacent
			}
		}
	}
	printf("shortest path \n");
	for(i=0;i<n;i++){
		printf("%d to %d is %d\n",s,i,d[i]);
	}
}
int main(){
	int n,i,j,c[10][10],s;
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	printf("enter the cost matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	printf("enter the souce\n");
	scanf("%d",&s);
	shortest(n,c,s);
}
