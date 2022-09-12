//C program to delete alternate nodes of a singly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}NODE;

typedef struct list
{
    NODE *head;
}LIST;

void init(LIST* pl);
void create(LIST* pl);
void del(LIST* pl);
void display(LIST* pl);

int main()
{
    LIST l1;
    init(&l1);
    create(&l1);
    display(&l1);

    del(&l1);
    display(&l1);

    return 0;
}

void init(LIST *pl)
{
    pl->head = NULL;
}

void create(LIST *pl)
{
    NODE* temp;
    int wish = 0;
    do
    {
        temp = (NODE*)malloc(sizeof(NODE));
        printf("Enter the integer: ");
        scanf("%d",&(temp->info));
        temp->next = NULL;
        
        temp->next = pl->head;
        pl-> head = temp;

        printf("Enter 1 to enter more elements.Else enter 0. ");
        scanf("%d",&wish);

    }while(wish);
}

void display(LIST *pl)
{
    NODE *p;    
    p = pl->head;
    if(pl->head == NULL)
    {
        printf("No elements in the list.\n");
    } 
   else
   {
        while(p!= NULL)
        {
            printf("%d ",p->info);
            p = p->next;
        }
    printf("\n");
   }
}

void del(LIST *pl)
{
    NODE *p = pl->head;
    if(pl->head == NULL)
    {
        printf("No elements in list to delete.\n");
    }
    else
    {
        while(p!=NULL && p->next!=NULL)
        {
            NODE* temp = p->next;
            p->next = p->next->next;
            p = p->next;
            free(temp);
        }
    }
}
