#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <stdio.h>

typedef int value_type;

typedef struct node{
	value_type value;
	struct node* next;
}node_t, *node_ptr;

typedef node_ptr list;

list create_list()
{
	//list point to header
	node_ptr header = (list)malloc(sizeof(node_t));
	if(NULL != header)
	{
		header->next = NULL;
	}
	
	return header;
}

node_ptr insert(node_ptr position, value_type value)
{
	node_ptr new_node = (node_ptr)malloc(sizeof(node_t));
	if(NULL == new_node)
	{
		return NULL;
	}

	new_node->value = value;	
	new_node->next = position->next;
	position->next = new_node;

	return new_node;
}

node_ptr previous(list l, node_ptr position)
{
	node_ptr p = l;
	while(NULL != p->next && position != p->next)
	{
		p = p->next;
	}

	//if not found
	if(NULL == p->next)
	{
		return NULL;
	}

	return p;
}

void delete(list l, node_ptr position)
{
	node_ptr pre = previous(l, position);
	if(NULL != pre)
	{
		pre->next = position->next;
		free(position);
	}
	
	return;
}

node_ptr find(list l, value_type value)
{
	node_ptr p = l->next;
	while(NULL != p && p->value != value)
	{
		p = p->next;
	}

	return p;
}

/* helper function
 */
value_type retrieve(node_ptr position)
{
	return position->value;
}

void clean(list l)
{
	node_ptr p, tmp;
	p = l->next;

	while(NULL != p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

node_ptr header(list l)
{
	return l;
}

node_ptr first(list l)
{
	return l->next;
}

int is_empty(list l)
{
	return NULL == l->next;
}

int is_last(node_ptr position)
{
	return NULL == position->next;
}

node_ptr advance(node_ptr position)
{
	return position->next;
}

void print_list(list l)
{
	node_ptr p = l->next;

	while(NULL != p)
	{
		printf("%d,", p->value);
		p = p->next;
	}

	printf("\n");
}
#endif // _LIST_H_

