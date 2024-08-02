#include<stdio.h>
#include<stdlib.h>
void gredy_knapsack(int n,int m,float p[],float w[]){//n is items,m is size,p for profits,w for weights
	float totprofit=0,max;//tp =total profit
	int i,k,count;
	for(count=0;count<n;count++)
	{
		max=0;
		for(i=0;i<n;i++){
			if((p[i]/w[i]>max)){
				k=i;//to track max item index
				max=p[i]/w[i];//find max ratio item
			}
		}
		if(w[k]<=m){
			printf("items %d with fraction 1 is selected\n",k);
			totprofit+=p[k];//update total profit
			m=m-w[k];//size-weight[k]
			p[k]=0;//update the already profited item to 0
		}
		else
		break;
	}
	printf("discreste knapsack profit=%f\n",totprofit);
	float x=m/w[k];//to involve the remaining portion to the sack get ratio of it and multiplyn the it with real profit u get profit of that remaining portion 
	//x=size/weight[k]
	totprofit+=p[k]*x;//add the remaining portion profit to the totalprofit
    printf("continous knapsack profit=%f",totprofit);
}  
int main(){
	int n,m,i;
	printf("enter the number of items\t");
	scanf("%d",&n);
	float *p,*w;
	p=(float*)malloc(n*sizeof(float));
	w=(float*)malloc(n*sizeof(float));
	printf("Enter the size");
	scanf("%d",&m);
	printf("Enter the profit of %d items\t",n);
	for(i=0;i<n;i++){
		scanf("%f",&p[i]);
	}
	printf("enter the weight of %d items\t",n);
	for(i=0;i<n;i++){
		scanf("%f",&w[i]);
	}
	gredy_knapsack(n,m,p,w);
	
}
