// CLINQ
// Defines the LINQ operations that directly modify the data content

#ifndef CLINQ_LINQ_DATA_H
#define CLINQ_LINQ_DATA_H

#include "list.h"
#include "functions.h"

COLLECTION	*linq_concat			(COLLECTION *src, COLLECTION *second);
COLLECTION	*linq_default_if_empty	(COLLECTION *src, void *default_value);
COLLECTION	*linq_reverse			(COLLECTION *src);

COLLECTION	*linq_skip				(COLLECTION *src, int count);
COLLECTION	*linq_skip_while		(COLLECTION *src, PREDICATE);
COLLECTION	*linq_take				(COLLECTION *src, int count);
COLLECTION	*linq_take_while		(COLLECTION *src, PREDICATE);

#endif