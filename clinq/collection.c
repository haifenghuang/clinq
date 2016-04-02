#include <stdio.h>
#include <stdlib.h>

#include "LINQ.h"
#include "collection.h"

//Function Declarations
//----------------------
static int clq_collection_insert(COLLECTION *src, void *element);
static int clq_collection_insert_distinct(COLLECTION *src, int TRANSFORM, void *element);
static int clq_collection_delete(COLLECTION *src, FREE_FUNC);
static int clq_collection_delete_where(COLLECTION *src, PREDICATE, FREE_FUNC);
static int clq_collection_size(COLLECTION *src);
static int clq_linq_all(COLLECTION *src, PREDICATE);
static int clq_linq_any(COLLECTION *src, PREDICATE);
static int clq_linq_contains(COLLECTION *src, void *element, COMPARITOR);
static COLLECTION *clq_linq_concat(COLLECTION *src, COLLECTION *second);
static COLLECTION *clq_linq_default_if_empty(COLLECTION *src, void *default_value);
static COLLECTION *clq_linq_reverse(COLLECTION *src);
static COLLECTION *clq_linq_skip(COLLECTION *src, int count);
static COLLECTION *clq_linq_skip_while(COLLECTION *src, PREDICATE);
static COLLECTION *clq_linq_take(COLLECTION *src, int count);
static COLLECTION *clq_linq_take_while(COLLECTION *src, PREDICATE);
static int	clq_linq_max(COLLECTION *src, int TRANSFORM);
static int	clq_linq_min(COLLECTION *src, int TRANSFORM);
static long	clq_linq_sum(COLLECTION *src, int TRANSFORM);
static long	clq_linq_long_count(COLLECTION *src, PREDICATE);
static float clq_linq_average(COLLECTION *src, int TRANSFORM);
static void	*clq_linq_max_element(COLLECTION *src, int TRANSFORM);
static void	*clq_linq_min_element(COLLECTION *src, int TRANSFORM);
static int	clq_linq_count(COLLECTION *src, PREDICATE);
static void	*clq_linq_element_at(COLLECTION *src, int index, void *default_value);
static void	*clq_linq_first(COLLECTION *src, PREDICATE, void *default_value);
static void	*clq_linq_last(COLLECTION *src, PREDICATE, void *default_value);
static void	*clq_linq_single(COLLECTION *src, PREDICATE, void *default_value);
static COLLECTION *clq_linq_where(COLLECTION *src, INDEX_PREDICATE);
static COLLECTION *clq_linq_distinct(COLLECTION *src, EQ_COMPARITOR);
static COLLECTION *clq_linq_except(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);
static COLLECTION *clq_linq_intersect(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);
static COLLECTION *clq_linq_union(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);


// Function Implementations
// ------------------------
clq_collection_t *clq_create()
{
	clq_collection_t *collection = malloc(sizeof(clq_collection_t));
	if (!collection) { return NULL; }

	 collection->data = clq_list_create();

	//Full out the functions of the collection
	collection->insert = clq_collection_insert;
	collection->insert_distinct = clq_collection_insert_distinct;
	collection->delete = clq_collection_delete;
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


void clq_destory(clq_collection_t *collection)
{
	if (collection)
	{
		//Free the other sections here....

		clq_list_destory(collection->data);
		free(collection);
	}
}

//Dispatchers for the LINQ functions
//ALL ensuring the provided source isn't NULL 
// --------------------------------------------------------------------------------
static int clq_collection_insert(COLLECTION *src, void *element) 
{
	if (!src) { return 0; }
	return clq_list_insert(src->data, element);
}	
static int clq_collection_insert_distinct(COLLECTION *src, int TRANSFORM,  void *element)
{
	if (!src) { return 0; }
	return clq_list_insert_distinct(src->data, transform, element);
}
static int clq_collection_delete( COLLECTION *src, FREE_FUNC)
{
	if (!src) { return 0; }
	if (free_func) { return clq_list_delete_free(src->data, free_func); }
	else { return clq_list_delete(src->data); }
}
static int clq_collection_delete_where (COLLECTION *src, PREDICATE, FREE_FUNC)
{
	if (!src) { return 0; }
	return clq_list_delete_where(src->data, predicate, free_func);
}
static int clq_collection_size (COLLECTION *src)
{
	if (!src) { return -1L; }
	return clq_list_size(src->data);
}
static int clq_linq_all(COLLECTION *src, PREDICATE)
{
	if (!src) { return 0; }
	return linq_all(src->data, predicate);
}
static int clq_linq_any(COLLECTION *src, PREDICATE)
{
	if (!src) { return 0; }
	return linq_any(src->data, predicate);
}
static int clq_linq_contains(COLLECTION *src, void *element, COMPARITOR)
{
	if (!src) { return 0; }
	return linq_contains(src->data, element, comparitor);
}
static COLLECTION *clq_linq_concat(COLLECTION *src, COLLECTION *second)
{
	if (!src) { return NULL; }
	return linq_concat(src->data, second->data);
}
static COLLECTION *clq_linq_default_if_empty(COLLECTION *src, void *default_value)
{
	if (!src) { return NULL; }
	return linq_default_if_empty(src->data, default_value);
}
static COLLECTION *clq_linq_reverse(COLLECTION *src)
{
	if (!src) { return NULL; }
	return linq_reverse(src->data);
}
static COLLECTION *clq_linq_skip(COLLECTION *src, int count)
{
	if (!src) { return NULL; }
	return linq_skip(src->data, count);
}
static COLLECTION *clq_linq_skip_while(COLLECTION *src, PREDICATE)
{
	if (!src) { return NULL; }
	return linq_skip_while(src->data, predicate);
}
static COLLECTION *clq_linq_take(COLLECTION *src, int count)
{
	if (!src) { return NULL; }
	return linq_take(src->data, count);
}
static COLLECTION *clq_linq_take_while(COLLECTION *src, PREDICATE)
{
	if (!src) { return NULL; }
	return linq_take_while(src->data, predicate);
}
static int	clq_linq_max(COLLECTION *src, int TRANSFORM)
{
	if (!src) { return 0; }
	return linq_max(src->data, transform);
}
static int	clq_linq_min(COLLECTION *src, int TRANSFORM)
{
	if (!src) { return 0; }
	return linq_min(src->data, transform);
}
static long	clq_linq_sum(COLLECTION *src, int TRANSFORM)
{
	if (!src) { return 0; }
	return linq_sum(src->data, transform);
}
static long	clq_linq_long_count(COLLECTION *src, PREDICATE)
{
	if (!src) { return 0L; }
	return linq_long_count(src->data, predicate);
}
static float clq_linq_average(COLLECTION *src, int TRANSFORM)
{
	if (!src) { return -1.0; }
	return linq_average(src->data, transform);
}
static void	*clq_linq_max_element(COLLECTION *src, int TRANSFORM)
{
	if (!src) { return 0; }
	return linq_max_element(src->data, transform);
}
static void	*clq_linq_min_element(COLLECTION *src, int TRANSFORM)
{
	if (!src) { return 0; }
	return linq_min_element(src->data, transform);
}
static int	clq_linq_count(COLLECTION *src, PREDICATE)
{
	if (!src) { return 0; }
	return linq_count(src->data, predicate);
}
static void	*clq_linq_element_at(COLLECTION *src, int index, void *default_value)
{
	if (!src) { return 0; }
	return linq_element_at(src->data, index, default_value);
}
static void	*clq_linq_first(COLLECTION *src, PREDICATE, void *default_value)
{
	if (!src) { return 0; }
	return linq_first(src->data, predicate, default_value);
}
static void	*clq_linq_last(COLLECTION *src, PREDICATE, void *default_value)
{
	if (!src) { return 0; }
	return linq_last(src->data, predicate, default_value);
}
static void	*clq_linq_single(COLLECTION *src, PREDICATE, void *default_value)
{
	if (!src) { return 0; }
	return linq_single(src->data, predicate, default_value);
}
static COLLECTION *clq_linq_where(COLLECTION *src, INDEX_PREDICATE)
{
	if (!src) { return NULL; }
	return linq_where(src->data, predicate);
}
static COLLECTION *clq_linq_distinct(COLLECTION *src, EQ_COMPARITOR)
{
	if (!src) { return NULL; }
	return linq_distinct(src->data, equality_comparitor);
}
static COLLECTION *clq_linq_except(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR)
{
	if (!src) { return NULL; }
	return linq_except(src->data, second->data, equality_comparitor);

}
static COLLECTION *clq_linq_intersect(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR)
{
	if (!src) { return NULL; }
	return linq_intersect(src->data, second->data, equality_comparitor);
}
static COLLECTION *clq_linq_union(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR)
{
	if (!src) { return NULL; }
	return linq_union(src->data, second->data, equality_comparitor);
}