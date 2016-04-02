#include <stdio.h>

#include "linq_query.h"

int			linq_count(COLLECTION *data, PREDICATE) { return 0; }


void		*linq_element_at(COLLECTION *src, int index, void *default_value) { return NULL; }
void		*linq_first(COLLECTION *src, PREDICATE, void *default_value) { return NULL; }
void		*linq_last(COLLECTION *src, PREDICATE, void *default_value) { return NULL; }
void		*linq_single(COLLECTION *src, PREDICATE, void *default_value) { return NULL; }

COLLECTION	*linq_where(COLLECTION *src, INDEX_PREDICATE) { return NULL; }