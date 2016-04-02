#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct clq_list
{
	struct clq_list_item *head;
	long size;
};

typedef struct clq_list_item
{
	void *data;
	struct clq_list_item *next;
}clq_list_item_t;


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


// TODO

int clq_list_insert(COLLECTION *src, void *element) { return 0; }
int clq_list_insert_distinct(COLLECTION *src, int TRANSFORM, void *element) { return 0; }
int clq_list_delete(COLLECTION *src, FREE_FUNC) { return 0; }
int clq_list_delete_where(COLLECTION *src, PREDICATE, FREE_FUNC) { return 0; }
long clq_list_size(COLLECTION *src) { return 0L; }
