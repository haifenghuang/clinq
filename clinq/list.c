#include "types.h"
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


clq_list_t *clq_list_create(int size)
{
	clq_list_t* list = malloc(sizeof(clq_list_t));
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