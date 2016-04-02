// CLINQ
// A linked-list implementation supporting LINQ functions
#ifndef CLINQ_LIST_H
#define CLINQ_LIST_H

#include "functions.h"

typedef struct clq_list clq_list_t;

clq_list_t *clq_list_create();
void clq_list_destory(clq_list_t *list);

int clq_list_insert						(COLLECTION *src, void *element);
int clq_list_insert_distinct			(COLLECTION *src, int TRANSFORM, void *element);
int clq_list_delete						(COLLECTION *src, FREE_FUNC);
int clq_list_delete_where				(COLLECTION *src, PREDICATE, FREE_FUNC);
long clq_list_size						(COLLECTION *src);

#endif