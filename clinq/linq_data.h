// CLINQ
// Defines the LINQ operations that directly modify the data content

#ifndef CLINQ_LINQ_DATA_H
#define CLINQ_LINQ_DATA_H

#include "list.h"
#include "functions.h"

COLLECTION	*linq_concat			(clq_list_t *src, clq_list_t *second);
COLLECTION	*linq_default_if_empty	(clq_list_t *src, void *default_value);
COLLECTION	*linq_reverse			(clq_list_t *src);

COLLECTION	*linq_skip				(clq_list_t *src, int count);
COLLECTION	*linq_skip_while		(clq_list_t *src, PREDICATE);
COLLECTION	*linq_take				(clq_list_t *src, int count);
COLLECTION *linq_take_while			(clq_list_t *src, PREDICATE);

#endif