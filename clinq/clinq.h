// CLINQ
// C LINQ like implementation in C

#ifndef CLINQ_H
#define CLINQ_H

#include "types.h"


// ------------------
// Easy Access Macros
// ------------------

#define CLQ_ALL(this, predicate) \
		(this)->all(this, predicate)

#define CLQ_ANY(this, predicate) \
		(this)->any(this, predicate)

#define CLQ_CONTAINS(this, element, comparitor) \
		(this)->contains(this, element, comparitor)

#define CLQ_COUNT(this, predicate) \
		(this)->count(this, predicate)

#define CLQ_SUM(this) \
		(this)->sum(this)

#define CLQ_LONG_COUNT(this, predicate) \
		(this)->long_count(this, predicate)

#define  CLQ_AVERAGE(this, transformation) \
		(this)->average(this, transformation)

#define CLQ_ELEMENT_AT(this, index, default_value) \
		(this)->element_at(this, index, default_value)

#define CLQ_FIRST(this, predicate, default_value) \
		(this)->first(this, predicate, default_value)

#define CLQ_LAST(this, predicate, default_value) \
		(this)->last(this, predicate, default_value)

#define CLQ_MAX(this, transformation) \
		(this)->max(this, transformation)

#define CLQ_MIN(this, transformation) \
		(this)->min(this, transformation)

#define CLQ_SINGLE(this, predicate, default_value) \
		(this)->single(this, predicate, default_value)

#define CLQ_CONCAT(this, second) \
		(this)->contat(this, second)

#define CLQ_DEFAULT_IF_EMPTY(this, default_value) \
		(this)->default_if_empty(this, default_value)

#define CLQ_DISTINCT(this, eq_comparitor) \
		(this)->distinct(this, ep_comparitor)

#define CLQ_EXCEPT(this, ep_comparitor) \
		(this)->except(this, ep_comparitor)

#define CLQ_INTERSECT(this, second, comparitor) \
		(this)->set_intersect(this, second, comparitor)

#define CLQ_REVERSE(this) \
		(this)->reverse(this)

#define CLQ_SKIP(this, index) \
		(this)->skip(this, index)

#define CLQ_SKIP_WHILE(this, predicate) \
		(this)->skip_while(this, predicate)

#define CLQ_TAKE(this, index) \
		(this)->take(this, index)

#define CLQ_TAKE_WHILE(this, predicate) \
		(this)->take_while(this, predicate)

#define CLQ_UNION(this, second) \
		(this)->set_union(this, second)

#define CLQ_WHERE(this, predicate) \
		(this)->where(this, predicate)

#endif