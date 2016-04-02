// CLINQ
// A linked-list implementation supporting LINQ functions
#ifndef CLINQ_LIST_H
#define CLINQ_LIST_H

#include "functions.h"

typedef struct clq_list_item
{
	void *data;
	struct clq_list_item *next;
}clq_item_t;

typedef struct clq_list
{
	struct clq_list_item *head;
	int size;
} clq_list_t;

clq_list_t *clq_list_create();
void clq_list_destory(clq_list_t *list);

int clq_list_insert				(clq_list_t *src, void *element);
int clq_list_insert_distinct	(clq_list_t *src, int TRANSFORM, void *element);
int clq_list_delete_free		(clq_list_t *src, FREE_FUNC);
int clq_list_delete				(clq_list_t *src);
int clq_list_delete_where		(clq_list_t *src, PREDICATE, FREE_FUNC);
int clq_list_size				(clq_list_t *src);

#endif