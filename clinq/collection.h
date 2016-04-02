#ifndef CLINQ_COLLECTION_H
#define CLINQ_COLLECTION_H

#include <stdio.h>

#include "clinq.h"
#include "list.h"

#define COLLECTION		struct clinq_collection
#define PREDICATE		int (*predicate)			(void *obj)
#define INDEX_PREDICATE int (*predicate)			(void *obj, int index)
#define COMPARITOR		int (*comparitor)			(void *objA, void *objB)
#define EQ_COMPARITOR	int (*equality_comparitor)	(void *objA, void *objB)
#define TRANSFORM			(*transform)			(void *obj)



// FUNCS

clq_collection_t *clq_collection_create();
void clq_collection_destory(clq_collection_t *collection);


#endif