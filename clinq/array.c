#include "types.h"
#include "array.h"

struct clq_array
{
	char *a;
	int b;
};



clq_collection_t *clq_array_create(int size)
{
	clq_array_t* array = malloc(sizeof(clq_array_t));
	if (!array) { return NULL; }

	//Init the array elements here...

	return array;
}


void clq_array_destory(clq_collection_t *array)
{
	//Free the array elements here....
	free(array);
}

