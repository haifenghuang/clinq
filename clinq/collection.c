#include <stdio.h>
#include <stdlib.h>

#include "LINQ.h"
#include "collection.h"


clq_collection_t *clq_create()
{
	clq_collection_t *collection = malloc(sizeof(clq_collection_t));
	if (!collection) { return NULL; }

	 collection->data = clq_list_create();

	//Full out the functions of the collection
	collection->insert = clq_collection_insert;
	collection->insert_distinct = clq_collection_insert_distinct;
	collection->clear = clq_collection_delete;
	collection->delete_where = clq_collection_delete_where;
	collection->size = clq_collection_size;

	collection->all = clq_linq_all;
	collection->any = clq_linq_any;
	collection->contains = clq_linq_contains;

	collection->count = clq_linq_count;
	collection->max_value = clq_linq_max;
	collection->min_value = clq_linq_min;

	collection->sum = clq_linq_sum;
	collection->long_count = clq_linq_long_count;

	collection->average = clq_linq_average;

	collection->element_at = clq_linq_element_at;
	collection->first = clq_linq_first;
	collection->last = clq_linq_last;
	collection->max_element = clq_linq_max_element;
	collection->min_element = clq_linq_min_element;
	collection->single = clq_linq_single;

	collection->concat = clq_linq_concat;
	collection->default_if_empty = clq_linq_default_if_empty;
	collection->distinct = clq_linq_distinct;
	collection->except = clq_linq_except;
	collection->set_intersect = clq_linq_intersect;
	collection->reverse = clq_linq_reverse;
	collection->skip = clq_linq_skip;
	collection->skip_while = clq_linq_skip_while;
	collection->take = clq_linq_take;
	collection->take_while = clq_linq_take_while;
	collection->set_union = clq_linq_union;
	collection->where = clq_linq_where;
	

	return collection;
}

void clq_destory(clq_collection_t *collection, FREE_FUNC)
{
	if (collection)
	{
		//Free the other sections here....

		clq_list_destory(collection->data, free_func);
		free(collection);
	}
}


//Dispatchers for the LINQ functions
//ALL ensuring the provided source isn't NULL 
// --------------------------------------------------------------------------------
int clq_collection_insert(CLQ_COLLECTION *src, void *element) 
{
	if (!src) { return 0; }
	return clq_list_insert(src->data, element);
}	
int clq_collection_insert_distinct(CLQ_COLLECTION *src, EQ_COMPARITOR,  void *element)
{
	if (!src) { return 0; }
	return clq_list_insert_distinct(src->data, equality_comparitor, element);
}
int clq_collection_delete( CLQ_COLLECTION *src, FREE_FUNC)
{
	if (!src) { return 0; }
	if (free_func) { return clq_list_clear_free(src->data, free_func); }
	else { return clq_list_clear(src->data); }
}
int clq_collection_delete_where (CLQ_COLLECTION *src, PREDICATE, FREE_FUNC)
{
	if (!src) { return 0; }
	return clq_list_delete_where(src->data, predicate, free_func);
}
int clq_collection_size (CLQ_COLLECTION *src)
{
	if (!src) { return -1L; }
	return clq_list_size(src->data);
}
int clq_linq_all(CLQ_COLLECTION *src, PREDICATE)
{
	if (!src) { return 0; }
	return linq_all(src->data, predicate);
}
int clq_linq_any(CLQ_COLLECTION *src, PREDICATE)
{
	if (!src) { return 0; }
	return linq_any(src->data, predicate);
}
int clq_linq_contains(CLQ_COLLECTION *src, void *element, COMPARITOR)
{
	if (!src) { return 0; }
	return linq_contains(src->data, element, comparitor);
}
CLQ_COLLECTION *clq_linq_concat(CLQ_COLLECTION *src, CLQ_COLLECTION *second)
{
	if (!src) { return NULL; }
	return linq_concat(src->data, second->data);
}
CLQ_COLLECTION *clq_linq_default_if_empty(CLQ_COLLECTION *src, void *default_value)
{
	if (!src) { return NULL; }
	return linq_default_if_empty(src->data, default_value);
}
CLQ_COLLECTION *clq_linq_reverse(CLQ_COLLECTION *src)
{
	if (!src) { return NULL; }
	return linq_reverse(src->data);
}
CLQ_COLLECTION *clq_linq_skip(CLQ_COLLECTION *src, int count)
{
	if (!src) { return NULL; }
	return linq_skip(src->data, count);
}
CLQ_COLLECTION *clq_linq_skip_while(CLQ_COLLECTION *src, PREDICATE)
{
	if (!src) { return NULL; }
	return linq_skip_while(src->data, predicate);
}
CLQ_COLLECTION *clq_linq_take(CLQ_COLLECTION *src, int count)
{
	if (!src) { return NULL; }
	return linq_take(src->data, count);
}
CLQ_COLLECTION *clq_linq_take_while(CLQ_COLLECTION *src, PREDICATE)
{
	if (!src) { return NULL; }
	return linq_take_while(src->data, predicate);
}
int	clq_linq_max(CLQ_COLLECTION *src, int TRANSFORM)
{
	if (!src) { return 0; }
	return linq_max(src->data, transform);
}
int	clq_linq_min(CLQ_COLLECTION *src, int TRANSFORM)
{
	if (!src) { return 0; }
	return linq_min(src->data, transform);
}
long	clq_linq_sum(CLQ_COLLECTION *src, int TRANSFORM)
{
	if (!src) { return 0; }
	return linq_sum(src->data, transform);
}
long	clq_linq_long_count(CLQ_COLLECTION *src, PREDICATE)
{
	if (!src) { return 0L; }
	return linq_long_count(src->data, predicate);
}
float clq_linq_average(CLQ_COLLECTION *src, int TRANSFORM)
{
	if (!src) { return -1.0; }
	return linq_average(src->data, transform);
}
void	*clq_linq_max_element(CLQ_COLLECTION *src, int TRANSFORM)
{
	if (!src) { return 0; }
	return linq_max_element(src->data, transform);
}
void	*clq_linq_min_element(CLQ_COLLECTION *src, int TRANSFORM)
{
	if (!src) { return 0; }
	return linq_min_element(src->data, transform);
}
int	clq_linq_count(CLQ_COLLECTION *src, PREDICATE)
{
	if (!src) { return 0; }
	return linq_count(src->data, predicate);
}
void	*clq_linq_element_at(CLQ_COLLECTION *src, int index, void *default_value)
{
	if (!src) { return 0; }
	return linq_element_at(src->data, index, default_value);
}
void	*clq_linq_first(CLQ_COLLECTION *src, PREDICATE, void *default_value)
{
	if (!src) { return 0; }
	return linq_first(src->data, predicate, default_value);
}
void	*clq_linq_last(CLQ_COLLECTION *src, PREDICATE, void *default_value)
{
	if (!src) { return 0; }
	return linq_last(src->data, predicate, default_value);
}
void	*clq_linq_single(CLQ_COLLECTION *src, PREDICATE, void *default_value)
{
	if (!src) { return 0; }
	return linq_single(src->data, predicate, default_value);
}
CLQ_COLLECTION *clq_linq_where(CLQ_COLLECTION *src, INDEX_PREDICATE)
{
	if (!src) { return NULL; }
	return linq_where(src->data, predicate);
}
CLQ_COLLECTION *clq_linq_distinct(CLQ_COLLECTION *src, EQ_COMPARITOR)
{
	if (!src) { return NULL; }
	return linq_distinct(src->data, equality_comparitor);
}
CLQ_COLLECTION *clq_linq_except(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR)
{
	if (!src) { return NULL; }
	return linq_except(src->data, second->data, equality_comparitor);

}
CLQ_COLLECTION *clq_linq_intersect(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR)
{
	if (!src) { return NULL; }
	return linq_intersect(src->data, second->data, equality_comparitor);
}
CLQ_COLLECTION *clq_linq_union(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR)
{
	if (!src) { return NULL; }
	return linq_union(src->data, second->data, equality_comparitor);
}