#include <stdio.h>

void findCount(int n, int* ones, int* zeros);

int main(){

    int n = 0;
    printf("Enter the required number:\n");
    scanf("%d",&n);

    int ones = 0;
    int zeros = 0;

    findCount(n,&ones,&zeros);
    printf("The number of ones is : %d and the number of zeros is: %d .\n",ones,zeros);
    return 0;
}

void findCount(int n, int* ones, int* zeros){

    while(n != 0){
        int result = n & 1;
        n = n>>1;
        if(result == 1){
            (*ones)++;
        }
        else{
            (*zeros)++;
        }
    }
}