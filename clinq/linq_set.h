// CLINQ
// Defines the LINQ operations returning the result of a set operation

#ifndef CLINQ_LINQ_SET_H
#define CLINQ_LINQ_SET_H

#include "darray.h"
#include "functions.h"

CLQ_COLLECTION *linq_distinct	(darray_t *src, EQ_COMPARITOR);
CLQ_COLLECTION *linq_except		(darray_t *src, darray_t *second, EQ_COMPARITOR);
CLQ_COLLECTION *linq_intersect	(darray_t *src, darray_t *second, EQ_COMPARITOR);
CLQ_COLLECTION *linq_union		(darray_t *src, darray_t *second, EQ_COMPARITOR);

#endif