#include <stdio.h>

#include "linq_query.h"

int			linq_count(clq_list_t *data, PREDICATE) { return 0; }


void		*linq_element_at(clq_list_t *src, int index, void *default_value) { return NULL; }
void		*linq_first(clq_list_t *src, PREDICATE, void *default_value) { return NULL; }
void		*linq_last(clq_list_t *src, PREDICATE, void *default_value) { return NULL; }
void		*linq_single(clq_list_t *src, PREDICATE, void *default_value) { return NULL; }

COLLECTION	*linq_where(clq_list_t *src, INDEX_PREDICATE) { return NULL; }