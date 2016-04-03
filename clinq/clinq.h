// CLINQ
// C LINQ like implementation in C

#ifndef CLINQ_H
#define CLINQ_H

#include "collection.h"


// ------------------
// Data Manipulation Macros
// ------------------
#define CLQ_INSERT(collection, element) \
		(collection)->insert(collection, element)

#define CLQ_INSERT_DISTINCT(collection, eq_comparitor, element) \
		(collection)->insert_distinct(collection, eq_comparitor, element)

#define CLQ_DELETE(collection, free_func) \
		(collection)->clear(collection, free_func)

#define CLQ_DELETE_WHERE(collection, predicate, free_func) \
		(collection)->delete_where(collection, predicate, free_func)

#define CLQ_SIZE(collection) \
		(collection)->size(collection)


// ------------------
// Easy Access Macros
// ------------------
#define CLQ_ALL(collection, predicate) \
		(collection)->all(collection, predicate)

#define CLQ_ANY(collection, predicate) \
		(collection)->any(collection, predicate)

#define CLQ_CONTAINS(collection, element, comparitor) \
		(collection)->contains(collection, element, comparitor)

#define CLQ_COUNT(collection, predicate) \
		(collection)->count(collection, predicate)

#define CLQ_SUM(collection) \
		(collection)->sum(collection)

#define CLQ_LONG_COUNT(collection, predicate) \
		(collection)->long_count(collection, predicate)

#define  CLQ_AVERAGE(collection, transformation) \
		(collection)->average(collection, transformation)

#define CLQ_ELEMENT_AT(collection, index, default_value) \
		(collection)->element_at(collection, index, default_value)

#define CLQ_FIRST(collection, predicate, default_value) \
		(collection)->first(collection, predicate, default_value)

#define CLQ_LAST(collection, predicate, default_value) \
		(collection)->last(collection, predicate, default_value)

#define CLQ_MAX_VALUE(collection, transformation) \
		(collection)->max_value(collection, transformation)

#define CLQ_MIN_VALUE(collection, transformation) \
		(collection)->min_value(collection, transformation)

#define CLQ_MAX_ELEMENT(collection, transformation) \
		(collection)->max_element(collection, transformation)

#define CLQ_MIN_ELEMENT(collection, transformation) \
		(collection)->min_element(collection, transformation)

#define CLQ_SINGLE(collection, predicate, default_value) \
		(collection)->single(collection, predicate, default_value)

#define CLQ_CONCAT(collection, second) \
		(collection)->contat(collection, second)

#define CLQ_DEFAULT_IF_EMPTY(collection, default_value) \
		(collection)->default_if_empty(collection, default_value)

#define CLQ_DISTINCT(collection, eq_comparitor) \
		(collection)->distinct(collection, ep_comparitor)

#define CLQ_EXCEPT(collection, ep_comparitor) \
		(collection)->except(collection, ep_comparitor)

#define CLQ_INTERSECT(collection, second, comparitor) \
		(collection)->set_intersect(collection, second, comparitor)

#define CLQ_REVERSE(collection) \
		(collection)->reverse(collection)

#define CLQ_SKIP(collection, index) \
		(collection)->skip(collection, index)

#define CLQ_SKIP_WHILE(collection, predicate) \
		(collection)->skip_while(collection, predicate)

#define CLQ_TAKE(collection, index) \
		(collection)->take(collection, index)

#define CLQ_TAKE_WHILE(collection, predicate) \
		(collection)->take_while(collection, predicate)

#define CLQ_UNION(collection, second) \
		(collection)->set_union(collection, second)

#define CLQ_WHERE(collection, predicate) \
		(collection)->where(collection, predicate)


//Funcs
clq_collection_t *clq_create(void);
void clq_destory(clq_collection_t *collection);

#endif