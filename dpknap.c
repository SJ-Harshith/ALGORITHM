#include<stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
void dp(int n,int m,int p[],int w[])
{   int i,j,v[n+1][m+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
                v[i][j]=0;
            else if(j<w[i])
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
             printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
    printf("Optimal profit: %d\n", V[n][m]);
    printf("Items selected: ");
    int res = V[n][m];
    j = m;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == V[i - 1][j])
            continue;
        else {
            printf("%d ", i);
            res -= p[i];
            j -= w[i];
        }
    }
    printf("\n");
}
}
int main(){
    int i,j,n,m;
    printf("enter the n ");
    scanf("%d",&n);
    printf("enter the capacity ");
    scanf("%d",&m);
    printf("enter the weights\n");
    int p[10],w[10];
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    printf("enter the profits\n");
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    dp(n,m,p,w);
}
