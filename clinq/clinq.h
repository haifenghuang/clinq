// CLINQ
// C LINQ like implementation in C

#ifndef CLINQ_H
#define CLINQ_H

#include "functions.h"

// ------------------
// Data Manipulation Macros
// ------------------
#define CLQ_INSERT(collection, element) \
		clq_collection_insert(collection, element)

#define CLQ_INSERT_DISTINCT(collection, eq_comparitor, element) \
		clq_collection_insert_distinct(collection, eq_comparitor, element)

#define CLQ_DELETE(collection, free_func) \
		clq_collection_delete(collection, free_func)

#define CLQ_DELETE_WHERE(collection, predicate, free_func) \
		clq_collection_delete_where(collection, predicate, free_func)

#define CLQ_SIZE(collection) \
		clq_collection_size(collection)


// ------------------
// Easy Access Macros
// ------------------
#define CLQ_ALL(collection, predicate) \
		clq_linq_all(collection, predicate)

#define CLQ_ANY(collection, predicate) \
		clq_linq_any(collection, predicate)

#define CLQ_CONTAINS(collection, element, eq_comparitor) \
		clq_linq_contains(collection, element, eq_comparitor)

#define CLQ_COUNT(collection, predicate) \
		clq_linq_count(collection, predicate)

#define CLQ_SUM(collection) \
		clq_linq_sum(collection)

#define CLQ_LONG_COUNT(collection, predicate) \
		clq_linq_long_count(collection, predicate)

#define  CLQ_AVERAGE(collection, transformation) \
		clq_linq_average(collection, transformation)

#define CLQ_ELEMENT_AT(collection, index, default_value) \
		clq_linq_element_at(collection, index, default_value)

#define CLQ_FIRST(collection, predicate, default_value) \
		clq_linq_first(collection, predicate, default_value)

#define CLQ_LAST(collection, predicate, default_value) \
		clq_linq_last(collection, predicate, default_value)

#define CLQ_MAX_VALUE(collection, transformation) \
		clq_linq_max_value(collection, transformation)

#define CLQ_MIN_VALUE(collection, transformation) \
		clq_linq_min_value(collection, transformation)

#define CLQ_MAX_ELEMENT(collection, transformation) \
		clq_linq_max_element(collection, transformation)

#define CLQ_MIN_ELEMENT(collection, transformation) \
		clq_linq_min_element(collection, transformation)

#define CLQ_SINGLE(collection, predicate, default_value) \
		clq_linq_single(collection, predicate, default_value)

#define CLQ_CONCAT(collection, second) \
		clq_linq_contat(collection, second)

#define CLQ_DEFAULT_IF_EMPTY(collection, default_value) \
		clq_linq_default_if_empty(collection, default_value)

#define CLQ_DISTINCT(collection, eq_comparitor) \
		clq_linq_distinct(collection, ep_comparitor)

#define CLQ_EXCEPT(collection, ep_comparitor) \
		clq_linq_except(collection, ep_comparitor)

#define CLQ_INTERSECT(collection, second, comparitor) \
		clq_linq_set_intersect(collection, second, comparitor)

#define CLQ_REVERSE(collection) \
		clq_linq_reverse(collection)

#define CLQ_SKIP(collection, index) \
		clq_linq_skip(collection, index)

#define CLQ_SKIP_WHILE(collection, predicate) \
		clq_linq_skip_while(collection, predicate)

#define CLQ_TAKE(collection, index) \
		clq_linq_take(collection, index)

#define CLQ_TAKE_WHILE(collection, predicate) \
		clq_linq_take_while(collection, predicate)

#define CLQ_UNION(collection, second) \
		clq_linq_set_union(collection, second)

#define CLQ_WHERE(collection, predicate) \
		clq_linq_where(collection, predicate)

//FUNCTIONS
CLQ_COLLECTION *clq_create(void);
void clq_destory(CLQ_COLLECTION *collection);

#endif