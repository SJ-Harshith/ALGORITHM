#include<stdio.h>
int x[10],d,w[10];
static int count =0;

void sumofsubsets(int s,int k,int rem){
	int i;
	x[k] = 1;
	if(s+w[k] == d)
	{
	   printf("subset=%d\n",++count);
	   for(i=0;i<=k;i++)
	   		if(x[i]==1){
	   			printf("%d ",w[i]);
			   }
		printf("\n");	
	}
	else if( s+ w[k]<d)
		sumofsubsets(s+w[k],k+1,rem-w[k]);
	if((s+rem-w[k]>=d)&&(s+w[k+1]<=d)){
		x[k]=0;
		sumofsubsets(s,k+1,rem-w[k]);
	}
}
int main(){
	int sum=0,n,i;
	printf("ENTER THE n \n");
	scanf("%d",&n);
	printf("enter the ele in increasing order\n");
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
		sum=sum+w[i];
	}
	printf("enter the d\n");
	scanf("%d",&d);
	if((sum<d)||(d<w[0]))
		printf("no subset possible ");
	else
	{
		sumofsubsets(0,0,sum);
		if(count==0)
			printf("no subset possible\n");
	}
}
