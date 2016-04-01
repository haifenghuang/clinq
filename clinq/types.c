#include "types.h"

#include "array.h"
#include "list.h"

clq_collection_t *clq_collection_create(clq_type type, int sz)
{
	clq_collection_t *collection = malloc(sizeof(clq_collection_t));
	if (!collection) { return NULL; }

	switch (type)
	{
		case CLQ_ARRAY: { collection->data = (void *)clq_array_create(sz); break; }
		case CLQ_LIST:  { collection->data = (void *)clq_list_create(); break; }
	}

	//Init the other sections here...

	return collection;
}


void clq_collection_destory(clq_collection_t *collection)
{
	if (collection)
	{
		//Free the other sections here....
		


		//Free the data element
		switch (collection->type)
		{
		case CLQ_ARRAY: { clq_array_destory(collection->data); break; }
		case CLQ_LIST:  { clq_list_destory(collection->data);  break; }
		default: {break; }
		}

		free(collection);
	}
}