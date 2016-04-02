#ifndef CLINQ_FUNCTIONS_H
#define CLINQ_FUNCTIONS_H

#define COLLECTION		struct clq_collection
#define PREDICATE		int		(*predicate)			(void *obj)
#define INDEX_PREDICATE int		(*predicate)			(void *obj, int index)
#define COMPARITOR		int		(*comparitor)			(void *objA, void *objB)
#define EQ_COMPARITOR	int		(*equality_comparitor)	(void *objA, void *objB)
#define TRANSFORM				(*transform)			(void *obj)
#define FREE_FUNC		void	(*free_func)			(void *obj)

#endif