#include "types.h"
#include "array.h"

struct clq_array
{
	void **elements;
	long size;
};



clq_array_t *clq_array_create(int size)
{
	clq_array_t* array = malloc(sizeof(clq_array_t));
	if (!array) { return NULL; }

	//Init the array elements here...
	array->elements = malloc(sizeof(void *) * size);
	if (!array->elements)
	{
		free(array);
		return NULL;
	}

	for (int i = 0; i < size; i++) { array->elements[0] = NULL; }
	array->size = size;

	return array;
}


void clq_array_destory(clq_array_t *array)
{
	free(array->elements);
	free(array);
}

