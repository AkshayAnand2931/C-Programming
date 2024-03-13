#include <stdio.h>
#include <stdlib.h>

int maxEvents(int ** eventPtrs, int eventSize, int eventsColSize)
{
    for(int i = 0; i<eventSize-1;i++)
    {
        for(int j = 0; j<eventSize -i - 1; j++)
        {
            if(eventPtrs[j][0] > eventPtrs[j+1][0])
            {
                int* temp = eventPtrs[j+1];
                eventPtrs[j+1] = eventPtrs[j];
                eventPtrs[j] = temp;
            }
        }
    }

    for(int i = 0; i<eventSize-1;i++)
    {
        for(int j = 0; j<eventSize - i - 1; j++)
        {
            if(eventPtrs[j][0] == eventPtrs[j+1][0] && eventPtrs[j][1] > eventPtrs[j+1][1])
            {
                int* temp = eventPtrs[j+1];
                eventPtrs[j+1] = eventPtrs[j];
                eventPtrs[j] = temp;
            }
        }
    }

    int day = 1;
    int max = 0;
    for(int i = 0; i<eventSize;i++)
    {
        if(eventPtrs[i][0]<= day && day<= eventPtrs[i][1])
        {
            max++;
            day++;
        }

    }

    return max;
}

int main()
{
    int events[1000][2];
    int* eventPtrs[1000];
    int eventSize = 0;
    int eventsColSize = 2;
    int count = 0;

    scanf("%d",&eventSize);
    while(count <eventSize && scanf("%d %d", &events[count][0],&events[count][1]) == 2)
    {
        eventPtrs[count] = events[count];
        count++;
    }

    int maxAttended = maxEvents(eventPtrs,eventSize,eventsColSize);
    printf("%d",maxAttended);
    return 0;

}