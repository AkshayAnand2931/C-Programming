//To implement a double-ended queue

#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
    int ele;
    struct node* next;
    struct node* prev;
}NODE;

typedef struct queue
{
    NODE* front;
    NODE* rear;
}QUEUE;

void init(QUEUE* pq);
void insertF(QUEUE *pq, int e);
void insertB(QUEUE *pq, int e);
void deleteF(QUEUE *pq, int *e);
void deleteB(QUEUE *pq, int *e);

int main()
{
    QUEUE q;
    init(&q);
    int choice,ele;
    printf("1. InsertFront 2.InsertBack 3.DeleteFront 4.DeleteRear");
    scanf("%d",&choice);
    do
    {
        switch(choice)
        {
            case 1:
            {
                printf("Enter the element");
                scanf("%d",&ele);
                insertF(&q,ele);
                break;
            }
            case 2:
            {
                printf("Enter the element");
                scanf("%d",&ele);
                insertF(&q,ele);
                break;
            }
            case 3:
            {
                deleteF(&q,&ele);
                printf("Element deleted is %d",ele);
                break;
            }
            case 4:
            {
                deleteF(&q,&ele);
                printf("Element deleted is %d",ele);
                break;  
            }

            printf("1. InsertFront 2.InsertBack 3.DeleteFront 4.DeleteRear");
            scanf("%d",&choice);
            
        }
    }while(choice < 5);
    return 0;
}

void init(QUEUE* pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

void insertF(QUEUE* pq, int e)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->ele = e;
    temp->next = NULL;
    temp->prev = NULL;
    
    if(pq->front == NULL)
    {
        temp->next = pq->front;
        pq->front = temp;
        pq->rear = temp;
    }
    else
    {
        temp->next = pq->front;
        pq->front = temp;
        temp->next->prev = temp;
    }
}

void insertB(QUEUE* pq, int e)
{
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->ele = e;
    temp->next = NULL;
    temp->prev = NULL;

    if(pq->rear == NULL)
    {
        temp->next = pq->front;
        pq->front = temp;
        pq->rear = temp; 
    }
    else
    {
        temp->prev = pq->rear;
        pq->rear = temp;
        temp->prev->next = temp;
    }
}

void deleteF(QUEUE* pq, int* e)
{
    if(pq->front == NULL)
    {
        printf("The queue is empty");
    }
    else
    {
        NODE* p = pq->front;
        *e = p->ele;
        pq->front = p->next;
        if(pq->front == NULL) pq->rear == NULL;
        free(p);
    }
}

void deleteB(QUEUE* pq,int* e)
{
    if(pq->rear == NULL)
    {
        printf("The queue is empty");
    }
    else
    {
        NODE* p = pq->rear;
        *e = p->ele;
        pq->rear = p->prev;
        p->prev->next = NULL;
        if(pq->rear == NULL) pq->front == NULL;
        free(p);
    }
}