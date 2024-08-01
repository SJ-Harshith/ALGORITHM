#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a[10], count = 0; // Array a to track queens positions where index=row,value=column
// Function to check if a queen can be placed in the current position
int place(int pos) {
    int i;
    for (i=0;i<pos;i++) {
        if(a[i]==a[pos]||abs(a[i]-a[pos])==abs(i-pos)){
            return 0; //Same columnorsame diagonal
        }
    }
    return 1;
}
//Function to print the solution
void printsoln(int n) {
    int i,j;
    count++;
    printf("Solution no = %d\n",count);
    for (i=0;i<n;i++) {
        for(j=0;j<n;j++){
            if (a[i]==j) {
                printf("Q\t");
            }else{
                printf("X\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}
void queen(int k,int n) {
    int i;
    if (k==n) {
        printsoln(n);// Print the solution when all queens are placed
    } else {
        for(i=0;i<n;i++) {
            a[k]=i; // Place the k-th queen in column i
            if (place(k)){
                queen(k+1,n); // Recur to place the next queen
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d",&n);
    queen(0,n);
    printf("Total number of solutions = %d\n", count);
    return 0;
}
