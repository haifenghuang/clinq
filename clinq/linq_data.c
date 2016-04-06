#include <stdio.h>

#include "linq_data.h"


CLQ_COLLECTION *linq_concat(clq_list_t *src, clq_list_t *second)
{ 
	CLQ_COLLECTION *newCol = clq_create();
	if (!newCol) { return NULL; }

	for (int i = 0; i < src->size; i++)
	{
		if (!clq_collection_insert(newCol, src->data[i]))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	for (int i = 0; i < src->size; i++)
	{
		if(!clq_collection_insert(newCol, second->data[i]))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	return newCol;
}

CLQ_COLLECTION	*linq_default_if_empty(clq_list_t *src, void *default_value) 
{ 
	CLQ_COLLECTION *newCol = NULL;

	if (clq_collection_size(src) == 0)
	{
		newCol = clq_create();
		if (!newCol) { return NULL; }

		if (!clq_collection_insert(newCol, default_value))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	return (newCol) ? newCol : src;
}

CLQ_COLLECTION	*linq_reverse(clq_list_t *src)
{
	for (int i = 0; i < (src->size / 2); i++)
	{
		void *temp = src->data[i];
		src->data[i] = src->data[(src->size - i)];
		src->data[(src->size - i)] = temp;
	}
	
	return src;
}


CLQ_COLLECTION *linq_skip(clq_list_t *src, int count)
{
	CLQ_COLLECTION *newCol = clq_create();
	if (!newCol) { return NULL; }

	for (int i = count; i < src->size; i++)
	{
		if (!clq_collection_insert(newCol, src->data[i]))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	return newCol;
}

CLQ_COLLECTION *linq_skip_while(clq_list_t *src, PREDICATE) 
{
	int index				 = 0;
	CLQ_COLLECTION *newCol	 = clq_create();
	if (!newCol) { return NULL; }

	while (predicate(src->data[index]) && index < src->size)
	{
		index++;
	}

	for (int i = index; i < src->size; i++)
	{
		if (!clq_collection_insert(newCol, src->data[i]))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	return newCol;
}


CLQ_COLLECTION *linq_take(clq_list_t *src, int count) 
{ 
	int itemCount			= (count <= src->size) ? count : src->size;
	CLQ_COLLECTION *newCol	= clq_create();
	if (!newCol) { return NULL; }

	for (int i = 0; i < itemCount; i++)
	{
		if (!clq_collection_insert(newCol, src->data[i]))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	return newCol;
}

CLQ_COLLECTION	*linq_take_while(clq_list_t *src, PREDICATE) 
{ 
	CLQ_COLLECTION *newCol = clq_create();
	if (!newCol) { return NULL; }

	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i]))
		{
			if (!clq_collection_insert(newCol, src->data[i]))
			{
				clq_destory(newCol);
				return NULL;
			}
		}
		else { break; }
	}

	return newCol;
}