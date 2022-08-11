#include <stdio.h>

/* To take input from the user for an array of integers and sort it using insertion sort*/

void init(int *p, int count);
void sort(int *p, int count);
void read(int *p, int count);

int main()
{
    int count;
    int array[100];
    
    printf("Enter the number of elements in a list: ");
    scanf("%d",&count);

    init(array,count);
    sort(array,count);
    printf("The sorted list is: \n");
    read(array,count);

    return 0;
}

void init(int *p, int count)
{
    for(int i = 0; i < count; i++)
    {
        printf("Enter the number: ");
        scanf("%d",&p[i]); 
    }
}

void read(int *p, int count)
{
    for(int i = 0; i < count; i++)
    {
        printf("%d\n",p[i]);
    }
}

void sort(int *p, int count)
{

}