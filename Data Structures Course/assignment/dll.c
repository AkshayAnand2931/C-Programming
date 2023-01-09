#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	list->size++;
	if(list->head == NULL)
	{
		list->head = temp;
		list->tail = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else
	{
		temp->next = list->head;
		temp->prev = NULL;
		list->head->prev = temp;
		list->head = temp;
	}
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	list->size++;
	if(list->tail == NULL)
	{
		list->tail = temp;
		list->head = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else
	{
		temp->prev = list->tail;
		temp->next = NULL;
		list->tail->next = temp;
		list->tail = temp;
	}
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	list->size++;
	node_t* previous = NULL;
	node_t* pres = list->head;
	while (pres!=NULL && pres->data != prev)
	{
		previous = pres;
		pres = pres->next;
	}
	if(pres == NULL)
	{
		list->size--;
		return;
	}
	temp->next = pres->next;
	temp->prev = pres;
	pres->next = temp;
	if(temp->next!=NULL)
	{
		temp->next->prev = temp;
	}
	if(list->tail == pres)
	{
		list->tail = list->tail->next;
	}
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	if(list->head == NULL)
	{
		return;
	}
	list->size--;
	node_t* del = list->head;
	list->head = list->head->next;
	if(list->head != NULL)
	{
		list->head->prev = NULL;
	}
	else
	{
		list->tail = NULL;
	}
	free(del);
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
	if(list->tail == NULL)
	{
		return;
	}
	list->size--;
	node_t* del = list->tail;
	list->tail = list->tail->prev;
	if(list->tail !=NULL)
	{
		list->tail->next = NULL;
	}
	else
	{
		list->head = NULL;
	}
	free(del);
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	if(list->head == NULL)
	{
		return;
	}
	list->size--;
	node_t* prev = NULL;
	node_t* pres = list->head;
	while(pres != NULL && pres->data != data)
	{
		prev = pres;
		pres = pres->next;
	}
	if(pres == NULL)
	{
		list->size++;
		return;
	}
	if(pres == list->head)
	{
		delete_front(list);
		return;
	}
	if(pres == list->tail)
	{
		delete_back(list);
		return;
	}
	prev->next = pres->next;
	prev->next->prev = prev;
	free(pres);
	pres = NULL;
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{
	node_t* prev = NULL;
	node_t* pres = list->head;
	while (pres != NULL && pres->data != data)
	{
		prev = pres;
		pres = pres->next;
	}
	return pres;
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

