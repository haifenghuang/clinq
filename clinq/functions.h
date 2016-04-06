#ifndef CLINQ_FUNCTIONS_H
#define CLINQ_FUNCTIONS_H

#define COLLECTION		struct clq_collection
#define PREDICATE		int		(*predicate)			(void *obj)
#define INDEX_PREDICATE int		(*predicate)			(void *obj, int index)
#define COMPARITOR		int		(*comparitor)			(void *objA, void *objB)
#define EQ_COMPARITOR	int		(*equality_comparitor)	(void *objA, void *objB)
#define TRANSFORM				(*transform)			(void *obj)
#define FREE_FUNC		void	(*free_func)			(void *obj)

//Function Declarations
//----------------------
int			clq_collection_insert(COLLECTION *src, void *element);
int			clq_collection_insert_distinct(COLLECTION *src, EQ_COMPARITOR, void *element);
int			clq_collection_delete(COLLECTION *src, FREE_FUNC);
int			clq_collection_delete_where(COLLECTION *src, PREDICATE, FREE_FUNC);
int			clq_collection_size(COLLECTION *src);
int			clq_linq_all(COLLECTION *src, PREDICATE);
int			clq_linq_any(COLLECTION *src, PREDICATE);
int			clq_linq_contains(COLLECTION *src, void *element, COMPARITOR);
COLLECTION	*clq_linq_concat(COLLECTION *src, COLLECTION *second);
COLLECTION	*clq_linq_default_if_empty(COLLECTION *src, void *default_value);
COLLECTION	*clq_linq_reverse(COLLECTION *src);
COLLECTION	*clq_linq_skip(COLLECTION *src, int count);
COLLECTION	*clq_linq_skip_while(COLLECTION *src, PREDICATE);
COLLECTION	*clq_linq_take(COLLECTION *src, int count);
COLLECTION	*clq_linq_take_while(COLLECTION *src, PREDICATE);
int			clq_linq_max(COLLECTION *src, int TRANSFORM);
int			clq_linq_min(COLLECTION *src, int TRANSFORM);
long		clq_linq_sum(COLLECTION *src, int TRANSFORM);
long		clq_linq_long_count(COLLECTION *src, PREDICATE);
float		clq_linq_average(COLLECTION *src, int TRANSFORM);
void		*clq_linq_max_element(COLLECTION *src, int TRANSFORM);
void		*clq_linq_min_element(COLLECTION *src, int TRANSFORM);
int			clq_linq_count(COLLECTION *src, PREDICATE);
void		*clq_linq_element_at(COLLECTION *src, int index, void *default_value);
void		*clq_linq_first(COLLECTION *src, PREDICATE, void *default_value);
void		*clq_linq_last(COLLECTION *src, PREDICATE, void *default_value);
void		*clq_linq_single(COLLECTION *src, PREDICATE, void *default_value);
COLLECTION	*clq_linq_where(COLLECTION *src, INDEX_PREDICATE);
COLLECTION	*clq_linq_distinct(COLLECTION *src, EQ_COMPARITOR);
COLLECTION	*clq_linq_except(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);
COLLECTION	*clq_linq_intersect(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);
COLLECTION	*clq_linq_union(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);

#endif