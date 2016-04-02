#include <stdio.h>
#include <stdlib.h>

#include "list.h"

clq_list_t *clq_list_create()
{
	clq_list_t *list = malloc(sizeof(clq_list_t));
	if (!list) { return NULL; }

	//Init the array elements here...
	list->data = malloc(sizeof(void *) * 2);
	if (!list->data)
	{
		free(list);
		return NULL;
	}

	//Init the sections to NULL
	//list->data[0] = NULL;
	//list->data[1] = NULL;

	list->array_size = 2; //Default size
	list->size = 0L;

	return list;
}


void clq_list_destory(clq_list_t *list)
{
	if (list)
	{
		for (int i = 0; i < list->size; i++)
		{
			free(list->data[i]);
		}

		free(list->data);
		free(list);
	}
}

int clq_list_size(clq_list_t *src)
{
	if (!src) { return -1L; }
	return src->size;
}

int clq_list_insert(clq_list_t *src, void *element)
{ 
	if (!src) { return 0; }

	if (src->size == src->array_size)
	{
		void **temp = realloc(src->data, sizeof(void *) * (src->array_size * 2));
		if (!temp) { return 0; }

		src->data = temp;
		src->array_size *= 2;

		printf("Reallocted to size: %d\n", src->array_size);
	}

	src->data[src->size++] = element;
	return 1;
}

int clq_list_delete(clq_list_t *src)
{
	if (!src) { return 0; }

	for (int i = 0; i < src->size; i++)
	{
		src->data[i] = NULL;
	}

	src->size = 0;
	return 1;
}


int clq_list_delete_free(clq_list_t *src, FREE_FUNC)
{ 
	if (!src) { return 0; }

	//clq_item_t *cursor = src->head;

	//while (cursor)
	//{
	//	clq_item_t *temp = cursor;
	//	cursor = cursor->next;
	//
	//	if (free_func) { free_func(temp->data); }
	//	free(temp);
	//	src->size--;
	//}

	//src->head = NULL;
	return 1;
}

int clq_list_delete_where(clq_list_t *src, PREDICATE, FREE_FUNC)
{
	if (!src) { return 0; }

	//clq_item_t *cursor = src->head;
	//clq_item_t *prev   = NULL;
	//
	//while (cursor)
	//{
	//	clq_item_t *temp = cursor;
	//	prev = cursor;
	//	cursor = cursor->next;
	//
	//	if (predicate(temp))
	//	{
	//		//Update list pointers
	//		if (prev == src->head) { src->head = cursor; }
	//		else { prev->next = cursor; }
	//
	//		//Free item
	//		if (free_func) { free_func(temp->data); }
	//		free(temp);
	//		src->size--;
	//	}
	//}

	//prev->next = NULL;

	////Setting the head to NULL if there's nothing left in the data
	//if (src->size == 0) { src->head = NULL; }
	return 1;
}


// TODO

int clq_list_insert_distinct(clq_list_t *src, int TRANSFORM, void *element) { return 0; }



