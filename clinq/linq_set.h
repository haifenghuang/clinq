// CLINQ
// Defines the LINQ operations returning the result of a set operation

#ifndef CLINQ_LINQ_SET_H
#define CLINQ_LINQ_SET_H

#include "list.h"
#include "functions.h"

COLLECTION *linq_distinct	(COLLECTION *src, EQ_COMPARITOR);
COLLECTION *linq_except		(COLLECTION *src, EQ_COMPARITOR);
COLLECTION *linq_intersect	(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);
COLLECTION *linq_union		(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);

#endif