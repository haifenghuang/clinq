#include <stdio.h>
#include <stdlib.h>

#include "darray.h"
#include "functions.h"

darray_t *darray_create()
{
	darray_t *dArray = malloc(sizeof(darray_t));
	if (!dArray) { return NULL; }

	//Init the array elements here...
	dArray->data = malloc(sizeof(void *) * DEFAULT_ARRAY_SIZE);
	if (!dArray->data)
	{
		free(dArray);
		return NULL;
	}

	dArray->array_size = DEFAULT_ARRAY_SIZE;
	dArray->size = 0L;

	return dArray;
}

void darray_destory(darray_t *arr)
{
	if (arr)
	{
		free(arr->data);
		free(arr);
	}
}

int darray_insert(darray_t *arr, void *element)
{
	if (arr->size == arr->array_size)
	{
		void **temp = realloc(arr->data, sizeof(void *) * (arr->array_size * ARRAY_GROW_FACTOR));
		if (!temp) { return 0; }

		arr->data = temp;
		arr->array_size *= 2;
	}

	arr->data[arr->size++] = element;
	return 1;
}

int darray_insert_distinct(darray_t *arr, void *element, EQ_COMPARITOR)
{
	//Check if it's already in existance
	for (int i = 0; i < arr->size; i++)
	{
		if (equality_comparitor(element, arr->data[i])) { return 0; }
	}

	//Resize list if required
	if (arr->size == arr->array_size)
	{
		void **temp = realloc(arr->data, sizeof(void *) * (arr->array_size * 2));
		if (!temp) { return 0; }

		arr->data = temp;
		arr->array_size *= 2;

		printf("Reallocted to size: %d\n", arr->array_size);
	}

	//Insert item
	arr->data[arr->size++] = element;
	return 1;
}

int darray_clear(darray_t *arr, FREE_FUNC)
{
	for (int i = 0; i < arr->size; i++)
	{
		if (free_func) { free_func(arr->data[i]); }
		arr->data[i] = NULL;
	}

	arr->size = 0;
	return 1;
}

int darray_delete_where(darray_t *arr, PREDICATE, FREE_FUNC)
{
	int shift_val = 0;

	for (int i = 0; i < arr->size; i++)
	{
		if (predicate(arr->data[i]))
		{
			if (free_func) { free_func(arr->data[i]); }
			shift_val++;
		}

		//Fill the holes in the array as we go, keeping it O(n)
		else { arr->data[i - shift_val] = arr->data[i]; }
	}
	arr->size -= shift_val;
	return 1;
}


