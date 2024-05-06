#include <stdio.h>
void main()
{
    int i, n, j, a[n], flag = 1;
    printf("enter the no of array elements ");
    scanf("%d", &n);
    printf("enter the array elements");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // algo
    for (i = 0; i <= n - 2; i++)
    {
        for (j = i + 1; j <= n - 1; j++)
        {
            if (a[i] == a[j])
                flag = 0;
        }
    }
    if (flag==1)
        printf("elements are  unique");
    else
        printf("elments are not unique ");
}