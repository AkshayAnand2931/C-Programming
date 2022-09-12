#include <stdio.h>
#include <stdlib.h>
#include "add_poly.h"

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
        printf("Enter the power: \n");
        scanf("%d",&(temp->power));
        printf("Enter the coefficient: \n");
        scanf("%d",&(temp->coef));
        temp->next = NULL;
        
        temp->next = pl-> head;
        pl-> head = temp;

        printf("Enter 1 to enter more elements.Else enter 0.\n");
        scanf("%d",&wish);

    }while(wish);
}

void add(LIST *pl1,LIST *pl2,LIST *pl3)
{
    NODE *p,*q;
    p = pl1->head;
    q = pl2->head;

    while(p!=NULL && q!= NULL)
    {
        NODE* temp = (NODE*)malloc(sizeof(NODE));

        if(p->power == q->power)
        {
            temp->power = p->power;
            temp-> coef = (p->coef) + (q-> coef);
            p = p->next;
            q = q->next;
        }
        else if(p->power > q-> power)
        {
            temp-> power = p-> power;
            temp->coef = p-> coef;
            p = p->next;
        }
        else if(q-> power > p-> power)
        {
            temp-> power = q-> power;
            temp-> coef = q->coef;
            q = q->next;
        }

        temp-> next = pl3->head;
        pl3->head = temp;
    }

    while(p!=NULL)
    {
        NODE *temp = (NODE*)malloc(sizeof(NODE));
        temp->coef = p->coef;
        temp->power = p-> power;
        temp->next = pl3->head;
        pl3->head = temp;
        p = p->next;
    }

    while(q!= NULL)
    {
        NODE *temp = (NODE*)malloc(sizeof(NODE));
        temp->coef = q->coef;
        temp->power = q-> power;
        temp->next = pl3->head;
        pl3->head = temp;
        q = q->next; 
    }
}

void display(LIST *pl)
{
    NODE *p;    
    p = pl->head;
    if(pl->head == NULL)
    {
         printf("No polynomial.\n");
    } 
   else
   {
    while(p!= NULL)
    {
        printf("%dx%d + ",p->coef,p->power);
        p = p->next;
    }
    printf("\n");
   }
}