// CLINQ
// A linked-list implementation supporting LINQ functions
#ifndef CLINQ_LIST_H
#define CLINQ_LIST_H

#include "functions.h"

typedef struct clq_list clq_list_t;

clq_list_t *clq_list_create();
void clq_list_destory(clq_list_t *list);

int clq_list_insert					(clq_list_t *src, void *element);
int clq_list_insert_distinct		(clq_list_t *src, int TRANSFORM, void *element);
int clq_list_delete					(clq_list_t *src, FREE_FUNC);
int clq_list_delete_where			(clq_list_t *src, PREDICATE, FREE_FUNC);
long clq_list_size					(clq_list_t *src);

COLLECTION	*clq_list_concat		(clq_list_t *src, clq_list_t *second);
COLLECTION	*clq_default_if_empty	(clq_list_t *src, void *default_value);
COLLECTION	*clq_reverse			(clq_list_t *src);


#endif