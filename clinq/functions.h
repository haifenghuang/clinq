#ifndef CLINQ_FUNCTIONS_H
#define CLINQ_FUNCTIONS_H

#define CLQ_COLLECTION		struct clq_collection
#define PREDICATE		int		(*predicate)			(void *obj)
#define INDEX_PREDICATE int		(*predicate)			(void *obj, int index)
#define COMPARITOR		int		(*comparitor)			(void *objA, void *objB)
#define EQ_COMPARITOR	int		(*equality_comparitor)	(void *objA, void *objB)
#define TRANSFORM				(*transform)			(void *obj)
#define FREE_FUNC		void	(*free_func)			(void *obj)

//Function Declarations
//----------------------
int				clq_collection_insert(CLQ_COLLECTION *src, void *element);
int				clq_collection_insert_distinct(CLQ_COLLECTION *src, EQ_COMPARITOR, void *element);
int				clq_collection_delete(CLQ_COLLECTION *src, FREE_FUNC);
int				clq_collection_delete_where(CLQ_COLLECTION *src, PREDICATE, FREE_FUNC);
int				clq_collection_size(CLQ_COLLECTION *src);
int				clq_linq_all(CLQ_COLLECTION *src, PREDICATE);
int				clq_linq_any(CLQ_COLLECTION *src, PREDICATE);
int				clq_linq_contains(CLQ_COLLECTION *src, void *element, COMPARITOR);
CLQ_COLLECTION	*clq_linq_concat(CLQ_COLLECTION *src, CLQ_COLLECTION *second);
CLQ_COLLECTION	*clq_linq_default_if_empty(CLQ_COLLECTION *src, void *default_value);
CLQ_COLLECTION	*clq_linq_reverse(CLQ_COLLECTION *src);
CLQ_COLLECTION	*clq_linq_skip(CLQ_COLLECTION *src, int count);
CLQ_COLLECTION	*clq_linq_skip_while(CLQ_COLLECTION *src, PREDICATE);
CLQ_COLLECTION	*clq_linq_take(CLQ_COLLECTION *src, int count);
CLQ_COLLECTION	*clq_linq_take_while(CLQ_COLLECTION *src, PREDICATE);
int				clq_linq_max(CLQ_COLLECTION *src, int TRANSFORM);
int				clq_linq_min(CLQ_COLLECTION *src, int TRANSFORM);
long			clq_linq_sum(CLQ_COLLECTION *src, int TRANSFORM);
long			clq_linq_long_count(CLQ_COLLECTION *src, PREDICATE);
float			clq_linq_average(CLQ_COLLECTION *src, int TRANSFORM);
void			*clq_linq_max_element(CLQ_COLLECTION *src, int TRANSFORM);
void			*clq_linq_min_element(CLQ_COLLECTION *src, int TRANSFORM);
int				clq_linq_count(CLQ_COLLECTION *src, PREDICATE);
void			*clq_linq_element_at(CLQ_COLLECTION *src, int index, void *default_value);
void			*clq_linq_first(CLQ_COLLECTION *src, PREDICATE, void *default_value);
void			*clq_linq_last(CLQ_COLLECTION *src, PREDICATE, void *default_value);
void			*clq_linq_single(CLQ_COLLECTION *src, PREDICATE, void *default_value);
CLQ_COLLECTION	*clq_linq_where(CLQ_COLLECTION *src, INDEX_PREDICATE);
CLQ_COLLECTION	*clq_linq_distinct(CLQ_COLLECTION *src, EQ_COMPARITOR);
CLQ_COLLECTION	*clq_linq_except(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR);
CLQ_COLLECTION	*clq_linq_intersect(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR);
CLQ_COLLECTION	*clq_linq_union(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR);

#endif