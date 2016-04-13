#include <limits.h>
#include <stdlib.h>

#include "LINQ.h"
#include "functions.h"
#include "darray.h"

CLQ_COLLECTION *clq_create()
{
	return (CLQ_COLLECTION *)darray_create();
}

void clq_destory(CLQ_COLLECTION *src)
{
	darray_t *arr = (darray_t *)src;
	
	if (arr) { darray_destory(arr); }
}



int clq_insert(CLQ_COLLECTION *src, void *element)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return darray_insert(arr, element);
}

int clq_insert_distinct(CLQ_COLLECTION *src, EQ_COMPARITOR, void *element)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return darray_insert_distinct(arr, element, equality_comparitor);
}

int clq_delete(CLQ_COLLECTION *src, FREE_FUNC)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return darray_clear(arr, free_func);
}

int clq_delete_where(CLQ_COLLECTION *src, PREDICATE, FREE_FUNC)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return darray_delete_where(arr, predicate, free_func);
}

long clq_size(CLQ_COLLECTION *src)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return -1; }

	return arr->size;
}

int clq_linq_all(CLQ_COLLECTION *src, PREDICATE)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_all(arr, predicate);
}

int clq_linq_any(CLQ_COLLECTION *src, PREDICATE)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_any(arr, predicate);
}

int clq_linq_contains(CLQ_COLLECTION *src, void *element, EQ_COMPARITOR)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_contains(arr, element, equality_comparitor);
}

CLQ_COLLECTION *clq_linq_concat(CLQ_COLLECTION *src, CLQ_COLLECTION *second)
{
	darray_t *firstArr = (darray_t *)src;
	darray_t *secondArr = (darray_t *)second;

	if (!firstArr || !secondArr) { return NULL; }
	return linq_concat(firstArr, secondArr);
}

CLQ_COLLECTION *clq_linq_default_if_empty(CLQ_COLLECTION *src, void *default_value)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_default_if_empty(arr, default_value);
}

CLQ_COLLECTION *clq_linq_reverse(CLQ_COLLECTION *src)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_reverse(arr);
}

CLQ_COLLECTION *clq_linq_skip(CLQ_COLLECTION *src, int count)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_skip(arr, count);
}

CLQ_COLLECTION *clq_linq_skip_while(CLQ_COLLECTION *src, PREDICATE)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_skip_while(arr, predicate);
}

CLQ_COLLECTION *clq_linq_take(CLQ_COLLECTION *src, int count)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_take(arr, count);
}

CLQ_COLLECTION *clq_linq_take_while(CLQ_COLLECTION *src, PREDICATE)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_take_while(arr, predicate);
}

int	clq_linq_max(CLQ_COLLECTION *src, int TRANSFORM)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return INT_MIN; }

	return linq_max(arr, transform);
}

int	clq_linq_min(CLQ_COLLECTION *src, int TRANSFORM)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return INT_MAX; }

	return linq_min(arr, transform);
}

long clq_linq_sum(CLQ_COLLECTION *src, int TRANSFORM)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_sum(arr, transform);
}

long clq_linq_long_count(CLQ_COLLECTION *src, PREDICATE)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_long_count(arr, predicate);
}

float clq_linq_average(CLQ_COLLECTION *src, int TRANSFORM)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return -1.0f; }

	return linq_average(arr, transform);
}

void *clq_linq_max_element(CLQ_COLLECTION *src, int TRANSFORM)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_max_element(arr, transform);
}

void *clq_linq_min_element(CLQ_COLLECTION *src, int TRANSFORM)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_min_element(arr, transform);
}

int	clq_linq_count(CLQ_COLLECTION *src, PREDICATE)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return 0; }

	return linq_count(arr, predicate);
}

void *clq_linq_element_at(CLQ_COLLECTION *src, int index, void *default_value)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return NULL; }

	return linq_element_at(arr, index, default_value);
}

void *clq_linq_first(CLQ_COLLECTION *src, PREDICATE, void *default_value)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return NULL; }

	return linq_first(arr, predicate, default_value);
}

void *clq_linq_last(CLQ_COLLECTION *src, PREDICATE, void *default_value)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return NULL; }

	return linq_last(arr, predicate, default_value);
}

void *clq_linq_single(CLQ_COLLECTION *src, PREDICATE, void *default_value)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return NULL; }

	return linq_single(arr, predicate, default_value);
}

CLQ_COLLECTION *clq_linq_where(CLQ_COLLECTION *src, INDEX_PREDICATE)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return NULL; }

	return linq_where(arr, predicate);
}

CLQ_COLLECTION *clq_linq_distinct(CLQ_COLLECTION *src, EQ_COMPARITOR)
{
	darray_t *arr = (darray_t *)src;
	if (!arr) { return NULL; }

	return linq_distinct(arr, equality_comparitor);
}

CLQ_COLLECTION *clq_linq_except(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR)
{
	darray_t *firstArr = (darray_t *)src;
	darray_t *secondArr = (darray_t *)second;

	if (!firstArr || !secondArr) { return NULL; }

	return linq_except(firstArr, secondArr, equality_comparitor);

}

CLQ_COLLECTION *clq_linq_intersect(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR)
{
	darray_t *firstArr = (darray_t *)src;
	darray_t *secondArr = (darray_t *)second;

	if (!firstArr || !secondArr) { return NULL; }
	return linq_intersect(firstArr, secondArr, equality_comparitor);
}

CLQ_COLLECTION *clq_linq_union(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR)
{
	darray_t *firstArr = (darray_t *)src;
	darray_t *secondArr = (darray_t *)second;

	if (!firstArr || !secondArr) { return NULL; }
	return linq_union(firstArr, secondArr, equality_comparitor);
}
