#include "types.h"
#include "list.h"

struct clq_list
{
	char *a;
	int b;
	int c;
};


clq_collection_t *clq_list_create(int size)
{
	clq_list_t* list = malloc(sizeof(clq_list_t));
	if (!list) { return NULL; }

	//Init the array elements here...

	return list;
}


void clq_list_destory(clq_collection_t *list)
{
	//Free the list elements here....
	free(list);
}