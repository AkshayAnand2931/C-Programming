#include<stdio.h>
#include<stdlib.h>

struct Task 
{
    int index;
    int enqueueTime;
    int processingTime;
};

int* getOrder(struct Task tasks[],int tasksSize, int* returnSize)
{

    int time = 0;
    int * result = (int*)malloc(tasksSize*sizeof(int));

    for(int count = 0; count< tasksSize;)
    {
        int value = -1;
        int min = 100;
        for(int i = 0; i<tasksSize;i++)
        {
            if((tasks[i].index != -1) && (time >= tasks[i].enqueueTime) && (tasks[i].processingTime<min))
            {
                min = tasks[i].processingTime;
                value = tasks[i].index;
            }
        }
        
        if(value == -1)
        {
            time++;
        }
        else
        {
            time = time + tasks[value].processingTime;
            result[count] = tasks[value].index;
            count++;
            tasks[value].index = -1;
        }
        
    }
    *returnSize = tasksSize;
    return result;
}

int main() 
{
    int tasksSize;
    scanf("%d", &tasksSize);

    struct Task tasks[tasksSize];
    for (int i = 0; i < tasksSize; i++) 
    {
        tasks[i].index = i;
        scanf("%d %d", &tasks[i].enqueueTime, &tasks[i].processingTime);
    }

    int returnSize;
    int* result = getOrder(tasks, tasksSize, &returnSize);

    for (int i = 0; i < returnSize; i++) 
    {
        printf("%d\n", result[i]);
    }
    free(result);
    return 0;
}