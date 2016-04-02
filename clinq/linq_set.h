// CLINQ
// Defines the LINQ operations returning the result of a set operation

#ifndef CLINQ_LINQ_SET_H
#define CLINQ_LINQ_SET_H

#include "list.h"
#include "functions.h"

COLLECTION *linq_distinct	(clq_list_t *src, EQ_COMPARITOR);
COLLECTION *linq_except		(clq_list_t *src, EQ_COMPARITOR);
COLLECTION *linq_intersect	(clq_list_t *src, clq_list_t *second, EQ_COMPARITOR);
COLLECTION *linq_union		(clq_list_t *src, clq_list_t *second, EQ_COMPARITOR);

#endif