// CLINQ
// Defines the LINQ operations return a result as part of a "query"

#ifndef CLINQ_LINQ_QUERY_H
#define CLINQ_LINQ_QUERY_H

#include "darray.h"
#include "functions.h"

int			linq_count			(darray_t *src, PREDICATE);
long		linq_long_count		(darray_t *src, PREDICATE);

void		*linq_element_at	(darray_t *src, int index, void *default_value);
void		*linq_first			(darray_t *src, PREDICATE, void *default_value);
void		*linq_last			(darray_t *src, PREDICATE, void *default_value);
void		*linq_single		(darray_t *src, PREDICATE, void *default_value);

CLQ_COLLECTION	*linq_where		(darray_t *src, INDEX_PREDICATE);	

#endif