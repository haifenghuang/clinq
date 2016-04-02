#ifndef CLINQ_COLLECTION_H
#define CLINQ_COLLECTION_H

#include "list.h"

typedef struct clq_collection clq_collection_t;

#define COLLECTION		struct clinq_collection
#define PREDICATE		int		(*predicate)			(void *obj)
#define INDEX_PREDICATE int		(*predicate)			(void *obj, int index)
#define COMPARITOR		int		(*comparitor)			(void *objA, void *objB)
#define EQ_COMPARITOR	int		(*equality_comparitor)	(void *objA, void *objB)
#define TRANSFORM				(*transform)			(void *obj)
#define FREE_FUNC		void	(*free_func)			(void *obj)

#endif