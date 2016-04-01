// CLINQ
// Contains definitions of all the CLINQ types supported

#ifndef CLINQ_TYPES_H
#define CLINQ_TYPES_H

#include "array.h"
#include "dict.h"
#include "list.h"


#define COLLECTION		struct clinq_collection
#define PREDICATE		int (*predicate)			(void *obj)
#define INDEX_PREDICATE int (*predicate)			(void *obj, int index)
#define COMPARITOR		int (*comparitor)			(void *objA, void *objB)
#define EQ_COMPARITOR	int (*equality_comparitor)	(void *objA, void *objB)
#define TRANSFORM			(*transform)			(void *obj)

//TODO remove(?)
typedef struct clq_array clq_array_t;
typedef struct clq_list clq_list_t;

typedef enum clq_type {
	ARRAY,
	LIST,
	DICTIONARY
} clq_type;


typedef struct clq_colleciton
{
	void		  *data;
	clq_type	  type;

	int			  (*all)				(COLLECTION *src, PREDICATE);							//ALL - Predicate returns true or false for each item.
	int			  (*any)				(COLLECTION *src, PREDICATE);							//ANY - Predicate returns true of false for each item.
	int			  (*contains)			(COLLECTION *src, void *element, COMPARITOR);			//CONTAINS - Checks if object contains the specific element, with the given comparitor
	int			  (*count)				(COLLECTION *src, PREDICATE);							//COUNT - The number of items that match the given predicate
	long		  (*sum)				(COLLECTION *src);										//SUM - NO PARAMS
	long		  (*long_count)			(COLLECTION *src, PREDICATE);							//LONG-COUNT - The number of items that match the given predicate, as a long
	float		  (*average)			(COLLECTION *src, int TRANSFORM);						//AVERAGE - Transform turns non-numerical types into a float value.
	void		* (*element_at)			(COLLECTION *src, int index, void *default_value);		//ELEMENT-AT - Returns the element at the specified index, or defaul value if none-found
	void		* (*first)				(COLLECTION *src, PREDICATE, void *default_value);		//FIRST - Gets the first element to match predicate, or default value is none match	
	void		* (*last)				(COLLECTION *src, PREDICATE, void *default_value);		//LAST - Gets the last value to match the predicate, or default value if none match	
	void		* (*max)				(COLLECTION *src, int TRANSFORM);						//MAX - Gets the max value after transforming each value in sequence
	void		* (*min)				(COLLECTION *src, int TRANSFORM);						//MIN - Gets the min value after transforming each value in sequence	
	void		* (*single)				(COLLECTION *src, PREDICATE, void *default_value);		//SINGLE - Gets the only value to match the predicate, or default value if more than one match
	COLLECTION	* (*concat)				(COLLECTION *src, COLLECTION *second);					//CONCAT - Joins 2 things together
	COLLECTION	* (*default_if_empty)	(COLLECTION *src, void *default_value);					//DEFAULT-IF-EMPTY - Returns either the sequence or a new sequence containing the default value if empty
	COLLECTION	* (*distinct)			(COLLECTION *src, EQ_COMPARITOR);						//DISTINCT - Returns the distinct elements in the sequence matching comparitor
	COLLECTION	* (*except)				(COLLECTION *src, EQ_COMPARITOR);						//EXCEPT - Returns the set different using provided comparitor
	COLLECTION	* (*set_intersect)		(COLLECTION *src, COLLECTION *second, COMPARITOR);		//INTERSET - Performs set interst section on both seqeunces
	COLLECTION	* (*reverse)			(COLLECTION *src);										//REVERSE - Reverses the order of the elements in the underlying representation
	COLLECTION	* (*skip)				(COLLECTION *src, int count);							//SKIP - Gets a sequence missing the first count values
	COLLECTION	* (*skip_while)			(COLLECTION *src, PREDICATE);							//SKIP-WHILE - Gets a sequence missing the first number of items that match the predicate
	COLLECTION	* (*take)				(COLLECTION *src, int count);							//TAKE - Gets a sequence containing the first count values
	COLLECTION	* (*take_while)			(COLLECTION *src, PREDICATE);							//TAKE-WHILE - Gets a sequence containing the first number of items that match the predicate
	COLLECTION	* (*set_union)			(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);	//UNION - Gets the set union of the 2 sequences
	COLLECTION	* (*where)				(COLLECTION *src, INDEX_PREDICATE);						//WHERE - Gets the values that match the predicate taking into account the index


	//MAYBE
	//COLLECTION	(*cast)				(COLLECTION *src, clinq_type dest);						//CAST - Transforms the underlying representation from one type to another.
	//int			(*eqauls)			(COLLECTION *src, COLLECTION *another);					//EQUALS - Return true is the 2 

} clq_collection_t;


#define CLQ_ALL(this, pred) \
		(this)->all(this, pred)

#define CLQ_ANY(this, pred) \
		(this)->any(this, pred)

#define CLQ_CONTAINS(this, element, comp) \
		(this)->contains(this, element, comp)

#define CLQ_COUNT(this, pred) \
		(this)->count(this, pred)

#define CLQ_SUM(this) \
		(this)->sum(this)

#define CLQ_LONG_COUNT(this, pred) \
		(this)->long_count(this, pred)

#define  CLQ_AVERAGE(this, trans) \
		(this)->average(this, trans)

#define CLQ_ELEMENT_AT(this, index, df_val) \
		(this)->element_at(this, index, df_val)

#define CLQ_FIRST(this, pred, df_val) \
		(this)->first(this, pred, df_val)

#define CLQ_LAST(this, pred, df_val) \
		(this)->last(this, pred, df_val)

#define CLQ_MAX(this, trans) \
		(this)->max(this, trans)

#define CLQ_MIN(this, trans) \
		(this)->min(this, trans)

#define CLQ_SINGLE(this, pred, df_val) \
		(this)->single(this, pred, df_val)

#define CLQ_CONCAT(this, second) \
		(this)->contat(this, second)

#define CLQ_DEFAULT_IF_EMPTY(this, df_val) \
		(this)->default_if_empty(this, df_val)

#define CLQ_DISTINCT(this, eq_comp) \
		(this)->distinct(this, ep_comp)

#define CLQ_EXCEPT(this, ep_comp) \
		(this)->except(this, ep_comp)

#define CLQ_INTERSECT(this, second, comp) \
		(this)->set_intersect(this, second, comp)

#define CLQ_REVERSE(this) \
		(this)->reverse(this)

#define CLQ_SKIP(this, index) \
		(this)->skip(this, index)

#define CLQ_SKIP_WHILE(this, pred) \
		(this)->skip_while(this, pred)

#define CLQ_TAKE(this, index) \
		(this)->take(this, index)

#define CLQ_TAKE_WHILE(this, pred) \
		(this)->take_while(this, pred)

#define CLQ_UNION(this, second) \
		(this)->set_union(this, second)

#define CLQ_WHERE(this, pred) \
		(this)->where(this, pred)


#endif