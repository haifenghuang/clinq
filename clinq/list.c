#include <stdio.h>
#include <stdlib.h>

#include "list.h"

clq_list_t *clq_list_create()
{
	clq_list_t *list = malloc(sizeof(clq_list_t));
	if (!list) { return NULL; }

	//Init the array elements here...
	list->head = NULL;
	list->size = 0L;

	return list;
}


void clq_list_destory(clq_list_t *list)
{
	clq_list_item_t *cursor = list->head;
	while (cursor)
	{
		clq_list_item_t *temp = cursor;
		cursor = cursor->next;

		free(temp);
	}

	free(list);
}


long clq_list_size(clq_list_t *src)
{
	if (!src) { return -1L; }
	return src->size;
}

// TODO

int clq_list_insert(clq_list_t *src, void *element) { return 0; }
int clq_list_insert_distinct(clq_list_t *src, int TRANSFORM, void *element) { return 0; }
int clq_list_delete(clq_list_t *src, FREE_FUNC) { return 0; }
int clq_list_delete_where(clq_list_t *src, PREDICATE, FREE_FUNC) { return 0; }

