#include <stdio.h>
#include <stdlib.h>

#include "darray.h"

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

