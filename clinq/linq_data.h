// CLINQ
// Defines the LINQ operations that directly modify the data content

#ifndef CLINQ_LINQ_DATA_H
#define CLINQ_LINQ_DATA_H

#include "darray.h"
#include "functions.h"

CLQ_COLLECTION	*linq_concat			(darray_t *src, darray_t *second);
CLQ_COLLECTION	*linq_default_if_empty	(darray_t *src, void *default_value);
CLQ_COLLECTION	*linq_reverse			(darray_t *src);

CLQ_COLLECTION	*linq_skip				(darray_t *src, int count);
CLQ_COLLECTION	*linq_skip_while		(darray_t *src, PREDICATE);
CLQ_COLLECTION	*linq_take				(darray_t *src, int count);
CLQ_COLLECTION *linq_take_while			(darray_t *src, PREDICATE);

#endif