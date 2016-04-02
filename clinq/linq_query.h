// CLINQ
// Defines the LINQ operations return a result as part of a "query"

#ifndef CLINQ_LINQ_QUERY_H
#define CLINQ_LINQ_QUERY_H

#include "list.h"
#include "functions.h"

int			linq_count			(COLLECTION *data, PREDICATE);

void		*linq_element_at	(COLLECTION *src, int index, void *default_value);
void		*linq_first			(COLLECTION *src, PREDICATE, void *default_value);
void		*linq_last			(COLLECTION *src, PREDICATE, void *default_value);
void		*linq_single		(COLLECTION *src, PREDICATE, void *default_value);

COLLECTION	*linq_where			(COLLECTION *src, INDEX_PREDICATE);	

#endif