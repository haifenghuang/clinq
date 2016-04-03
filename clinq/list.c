#include <stdio.h>
#include <stdlib.h>

#include "list.h"

clq_list_t *clq_list_create()
{
	clq_list_t *list = malloc(sizeof(clq_list_t));
	if (!list) { return NULL; }

	//Init the array elements here...
	list->data = malloc(sizeof(void *) * DEFAULT_ARRAY_SIZE);
	if (!list->data)
	{
		free(list);
		return NULL;
	}

	list->array_size = DEFAULT_ARRAY_SIZE;
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
		void **temp = realloc(src->data, sizeof(void *) * (src->array_size * ARRAY_GROW_FACTOR));
		if (!temp) { return 0; }

		src->data = temp;
		src->array_size *= 2;
	}

	src->data[src->size++] = element;
	return 1;
}

int clq_list_clear(clq_list_t *src)
{
	if (!src) { return 0; }

	for (int i = 0; i < src->size; i++)
	{
		src->data[i] = NULL;
	}

	src->size = 0;
	return 1;
}


int clq_list_clear_free(clq_list_t *src, FREE_FUNC)
{ 
	if (!src) { return 0; }

	for (int i = 0; i < src->size; i++)
	{
		free_func(src->data[i]);
		src->data[i] = NULL;
	}

	src->size = 0;
	return 1;
}

int clq_list_delete_where(clq_list_t *src, PREDICATE, FREE_FUNC)
{
	if (!src) { return 0; }

	int shift_val = 0;

	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i]))
		{
			if (free_func) { free_func(src->data[i]); }
			shift_val++;
		}
		
		//Fill the holes in the array as we go, keeping it O(n)
		else { src->data[i - shift_val] = src->data[i]; }
	}
	src->size -= shift_val;
	return 1;
}

int clq_list_insert_distinct(clq_list_t *src, EQ_COMPARITOR, void *element)
{
	if (!src) { return 0; }

	//Check if it's already in existance
	for (int i = 0; i < src->size; i++)
	{
		if (equality_comparitor(element, src->data[i])) { return 0; }
	}

	//Resize list if required
	if (src->size == src->array_size)
	{
		void **temp = realloc(src->data, sizeof(void *) * (src->array_size * 2));
		if (!temp) { return 0; }

		src->data = temp;
		src->array_size *= 2;

		printf("Reallocted to size: %d\n", src->array_size);
	}

	//Insert item
	src->data[src->size++] = element;
	return 1;
}
