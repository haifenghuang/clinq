#include "collection.h"


clq_collection_t *clq_collection_create()
{
	clq_collection_t *collection = malloc(sizeof(clq_collection_t));
	if (!collection) { return NULL; }

	 collection->data = (void *)clq_list_create();

	//Init the other sections here...

	return collection;
}


void clq_collection_destory(clq_collection_t *collection)
{
	if (collection)
	{
		//Free the other sections here....

		clq_list_destory(collection->data);
		free(collection);
	}
}