#include <stdio.h>

#include "linq_query.h"

int	linq_count(clq_list_t *src, PREDICATE) 
{ 
	int count = 0;

	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i])) { count++; }
	}

	return count; 
}

long linq_long_count(clq_list_t *src, PREDICATE) 
{ 
	long count = 0L;

	for (long i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i])) { count++; }
	}

	return count; 
}

void *linq_element_at(clq_list_t *src, int index, void *default_value) 
{
	return (index <= src->size) ? src->data[index] : default_value;
}


void *linq_first(clq_list_t *src, PREDICATE, void *default_value)
{ 
	int index = 0;
	while (!predicate(src->data[index]) && index < src->size)
	{
		index++;
	}

	return (index < src->size) ? src->data[index] : default_value;
}

void *linq_last(clq_list_t *src, PREDICATE, void *default_value) 
{ 
	void *element = NULL;
	
	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i])) { element = src->data[i]; }
	}

	return element;
}

void *linq_single(clq_list_t *src, PREDICATE, void *default_value) 
{ 
	int		numFound = 0;
	void	*element = NULL;

	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i])) 
		{ 
			element = src->data[i];
			numFound++;
		}
	}

	return (numFound == 1) ? element : default_value;
}


CLQ_COLLECTION *linq_where(clq_list_t *src, INDEX_PREDICATE) 
{ 
	CLQ_COLLECTION *newCol = clq_create();
	if (!newCol) { return NULL; }

	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i], i))
		{
			if (!clq_collection_insert(newCol, src->data[i]))
			{
				clq_destory(newCol);
				return NULL;
			}
		}
	}

	return newCol;
}