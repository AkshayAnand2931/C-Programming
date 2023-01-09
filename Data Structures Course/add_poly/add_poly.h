typedef struct node
{
    int power;
    int coef;
    struct node* next;
}NODE;

typedef struct list
{
    NODE* head;
}LIST;

void init(LIST* pl);
void create(LIST* pl);
void add(LIST* pl1,LIST* pl2,LIST* pl3);
void display(LIST* pl);