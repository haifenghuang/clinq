// CLINQ
// Defines the LINQ operations returning a boolean value

#ifndef CLINQ_LINQ_BOOL_H
#define CLINQ_LINQ_BOOL_H

#include "darray.h"
#include "functions.h"

int linq_all		(darray_t *data, PREDICATE);
int linq_any		(darray_t *data, PREDICATE);
int linq_contains	(darray_t *data, void *element, EQ_COMPARITOR);

#endif