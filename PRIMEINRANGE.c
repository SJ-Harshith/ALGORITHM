#include<stdio.h>
#include<math.h>
void prime(int n)
{
    int i,j,k;
    int a[n+1];
    for(i=2;i<=n;i++)//gets an array elements from 2 to n
    {
        a[i]=i;
    }
    for(i=2;i<=floor(sqrt(n));i++)
    {
        if(a[i]!=0)
        {
            j=i*i;
            while(j<=n)
            {
                a[j]=0;
                j=j+i;
            }
        }
    }
    k=0;
    for(i=2;i<=n;i++){
     if (a[i]!=0){
        printf("%d\t",a[i]);
        k=k+1;
     }
    }
   
}
void main(){
int n;
printf("enter the range");
scanf("%d",&n);
prime(n);
}