#include "linq_bool.h"

int linq_all(clq_list_t *src, PREDICATE) 
{
	for (int i = 0; i < src->size; i++)
	{
		if (!predicate(src->data[i])) { return 0; }
	}
	return 1;
}

int linq_any(clq_list_t *src, PREDICATE) 
{ 
	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i])) { return 1; }
	}
	return 0; 
}

int linq_contains(clq_list_t *src, void *element, EQ_COMPARITOR)
{ 
	for (int i = 0; i < src->size; i++)
	{
		if (equality_comparitor(element, src->data[i])) { return 1; }
	}
	return 0;
}