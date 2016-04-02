// CLINQ
// Defines the LINQ operations returning a boolean value

#ifndef CLINQ_LINQ_BOOL_H
#define CLINQ_LINQ_BOOL_H

#include "list.h"
#include "functions.h"

int linq_all		(COLLECTION *data, PREDICATE);
int linq_any		(COLLECTION *data, PREDICATE);
int linq_contains	(COLLECTION *data, void *element, COMPARITOR);

#endif