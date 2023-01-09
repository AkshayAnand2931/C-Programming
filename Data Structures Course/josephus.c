#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node
{
    int info;
    struct node* next;
}NODE;

typedef struct circular
{
    NODE* head;
}CLIST;

void init(CLIST *pc);
int create(CLIST *pc);
void disp(CLIST *pc);
void josephus(CLIST *pc, int start, int skip);

int main()
{
    CLIST list;
    init(&list);

    int size = create(&list);
    disp(&list);
    srand(time(0));
    int start = (rand() % size) + 1;
    int skip = (rand() % size) + 1;
    printf("%d %d \n",start,skip);
    josephus(&list,start,skip);
    disp(&list);
    return 0;
}

void init(CLIST *pc)
{
    pc->head = NULL;
}

int create(CLIST *pc)
{
    int size = 0,choice = 0;
    do
    {   
        NODE *temp = (NODE*)malloc(sizeof(NODE));
        size++;
        printf("Enter the value to be entered.");
        scanf("%d",&(temp->info));
        temp->next = NULL;

        if(pc->head == NULL)
        {
            pc->head = temp;
            temp->next = temp;
        }
        else
        {
            NODE *p = pc->head;
            while(p->next != pc->head)
            {
                p = p->next;
            }
            p->next = temp;
            temp->next = pc->head;
        }
        printf("Do you want to continue?");
        scanf("%d",&choice);
    }while(choice);
    return size; 
}

void disp(CLIST *pc)
{
    if(pc->head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        NODE *p = pc->head;
        while(p->next != pc->head)
        {
            printf("%d ",p->info);
            p = p->next;
        }
        printf("%d \n",p->info);
    }
}

void josephus(CLIST *pc, int start, int skip)
{
    NODE *pres = pc->head;
    NODE *prev = NULL;

    for(int i = 1; i< start; i++)
    {
        prev = pres;
        pres = pres->next;
    }
    printf("start at %d --------\n",pres->info);
    
    while(pc->head->next != pc->head)
    {
        for(int j = 1; j<skip; j++)
        {
            prev = pres;
            pres = pres->next;
        }
        printf("Delete at %d -------\n",pres->info);
        prev->next = pres->next;
        if(pres == pc->head)
        {
            pc->head = pres->next;
        }
        free(pres);
        pres = prev->next;
    }
}