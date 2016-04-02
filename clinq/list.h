// CLINQ
// A linked-list implementation supporting LINQ functions
#ifndef CLINQ_LIST_H
#define CLINQ_LIST_H

#include "functions.h"

//typedef struct clq_list_item
//{
//	void *data;
//	struct clq_list_item *next;
//	struct clq_item_item *prev;
//}clq_item_t;

typedef struct clq_list
{
	void **data;
	int array_size;
	int size;
} clq_list_t;

clq_list_t *clq_list_create();
void clq_list_destory(clq_list_t *list);

int clq_list_insert				(clq_list_t *src, void *element);
int clq_list_insert_distinct	(clq_list_t *src, EQ_COMPARITOR, void *element);
int clq_list_delete_free		(clq_list_t *src, FREE_FUNC);
int clq_list_delete				(clq_list_t *src);
int clq_list_delete_where		(clq_list_t *src, PREDICATE, FREE_FUNC);
int clq_list_size				(clq_list_t *src);

#endif