#include<stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
void dp(int n,int m,int p[],int w[]){
    int i,j,v[n+1][m+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0||j==0){
                v[i][j]=0;
            }
            else if(j<w[i])
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
    printf("optimal soln =%d",v[n][m]);
    printf("\nselected items are ");
    while(n!=0){
        if(v[n][m]!=v[n-1][m]){
            printf("%d\t",n);
            m=m-w[n];
        }
        n--;
    }
}
int main(){
    int n,m,p[10],w[10],i;
    printf("Enter the n ");
    scanf("%d",&n);
    printf("ENTER the m");
    scanf("%d",&m);
    printf("\nenter the profits\n");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("\nenter the weights\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    dp(n,m,p,w);
}