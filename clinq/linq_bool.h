// CLINQ
// Defines the LINQ operations returning a boolean value

#ifndef CLINQ_LINQ_BOOL_H
#define CLINQ_LINQ_BOOL_H

#include "list.h"
#include "functions.h"

int linq_all		(clq_list_t *data, PREDICATE);
int linq_any		(clq_list_t *data, PREDICATE);
int linq_contains	(clq_list_t *data, void *element, COMPARITOR);

#endif