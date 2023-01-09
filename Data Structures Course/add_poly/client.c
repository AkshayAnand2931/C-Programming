//Add 2 polynomials using singly linked list

#include <stdio.h>
#include "add_poly.h"

int main()
{
    LIST l1;
    LIST l2;
    LIST l3;

    init(&l1);
    init(&l2);
    init(&l3);

    create(&l1);
    display(&l1);

    create(&l2);
    display(&l2);

    add(&l1,&l2,&l3);
    display(&l3);

    return 0;
}