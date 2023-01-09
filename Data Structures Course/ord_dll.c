//Create an ordered doubly linked list and search for a given info
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
    struct node *prev;
}NODE;

typedef struct dll
{
    NODE* head;
}LIST;

void init(LIST *pl);
void create(LIST *pl);
void disp(LIST *pl);
void search(LIST *pl, int key);

int main()
{
    int key;
    LIST l;
    init(&l);
    create(&l);
    disp(&l);
    printf("Enter the element which you want to search: ");
    scanf("%d",&key);
    search(&l,key);
    return 0;
}

void init(LIST *pl)
{
    pl->head = NULL;
}

void create(LIST *pl)
{
    int wish;
    do
    {   
        NODE* temp = (NODE*)malloc(sizeof(NODE));
        printf("Enter the value you want to add: ");
        scanf("%d",&(temp->info));
        temp->next = NULL;
        temp->prev = NULL;

        if(pl->head == NULL)
        {
            pl->head = temp;
            temp->prev = pl->head;
        }
        else
        {   
            NODE *prev = NULL;
            NODE *pres = pl->head;

            while((pres != NULL) && ((temp->info))>=(pres->info))
            {
                prev = pres;
                pres = pres->next;
            }
            temp->next = pres;
            temp->prev = prev;
            prev->next = temp;
            if(pres!= NULL)
            {
                pres->prev = temp;
            }
        }

        printf("Do you want to enter another number? ");
        scanf("%d",&wish);
    }while(wish);
}

void disp(LIST *pl)
{   printf("\n");
    if(pl->head == NULL)
    {
        printf("No elements in the list: ");
    }
    else
    {
        NODE* p = pl->head;
        while(p!= NULL)
        {
            printf("%d ",p->info);
            p = p->next;
        }
    }
}

void search(LIST *pl,int key)
{
    if(pl->head == NULL)
    {
        printf("The list is empty");
    }
    else
    {
        int count = 0;
        NODE *p = pl->head;
        while(p!=NULL)
        {
            if(key == (p->info))
            {
                count++;
            }
            p = p->next;
        }
        if(count)
        {
            printf("The given value is present in the list.\n");
        }
        else
        {
            printf("The given value is not present in the list.\n");
        }
    }
}