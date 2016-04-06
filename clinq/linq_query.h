// CLINQ
// Defines the LINQ operations return a result as part of a "query"

#ifndef CLINQ_LINQ_QUERY_H
#define CLINQ_LINQ_QUERY_H

#include "list.h"
#include "functions.h"

int			linq_count			(clq_list_t *src, PREDICATE);
long		linq_long_count		(clq_list_t *src, PREDICATE);

void		*linq_element_at	(clq_list_t *src, int index, void *default_value);
void		*linq_first			(clq_list_t *src, PREDICATE, void *default_value);
void		*linq_last			(clq_list_t *src, PREDICATE, void *default_value);
void		*linq_single		(clq_list_t *src, PREDICATE, void *default_value);

CLQ_COLLECTION	*linq_where			(clq_list_t *src, INDEX_PREDICATE);	

#endif