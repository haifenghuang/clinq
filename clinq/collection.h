#ifndef CLINQ_CLQ_COLLECTION_H
#define CLINQ_CLQ_COLLECTION_H

#include "list.h"
#include "functions.h"

typedef struct clq_collection
{
	clq_list_t		*data;

	int				(*insert)				(CLQ_COLLECTION *src, void *element);							//INSERT - Add an item into the list ignoring duplicates
	int				(*insert_distinct)		(CLQ_COLLECTION *src, EQ_COMPARITOR, void *element);			//INSERT-DISTINCT - Add an item in the collection, checking for duplicates
	int				(*clear)				(CLQ_COLLECTION *src, FREE_FUNC);								//DELETE - Clears the entire collection
	int				(*delete_where)			(CLQ_COLLECTION *src, PREDICATE, FREE_FUNC);					//DELETE-WHERE - Delete all items that match the predicate
	int				(*size)					(CLQ_COLLECTION *src);											//SIZE - Returns the collection size

	int				(*all)					(CLQ_COLLECTION *src, PREDICATE);								//ALL - Predicate returns true or false for each item.
	int				(*any)					(CLQ_COLLECTION *src, PREDICATE);								//ANY - Predicate returns true of false for each item.
	int				(*contains)				(CLQ_COLLECTION *src, void *element, COMPARITOR);				//CONTAINS - Checks if object contains the specific element, with the given comparitor
	int				(*count)				(CLQ_COLLECTION *src, PREDICATE);								//COUNT - The number of items that match the given predicate
	int				(*max_value)			(CLQ_COLLECTION *src, int TRANSFORM);							//MAX - Gets the max value after transforming each value in sequence
	int				(*min_value)			(CLQ_COLLECTION *src, int TRANSFORM);							//MIN - Gets the min value after transforming each value in sequence	
	long			(*sum)					(CLQ_COLLECTION *src, int TRANSFORM);							//SUM - Gets the total value of the items in the collection
	long			(*long_count)			(CLQ_COLLECTION *src, PREDICATE);								//LONG-COUNT - The number of items that match the given predicate, as a long
	float			(*average)				(CLQ_COLLECTION *src, int TRANSFORM);							//AVERAGE - Transform turns non-numerical types into a float value.
	void			* (*element_at)			(CLQ_COLLECTION *src, int index, void *default_value);			//ELEMENT-AT - Returns the element at the specified index, or defaul value if none-found
	void			* (*first)				(CLQ_COLLECTION *src, PREDICATE, void *default_value);			//FIRST - Gets the first element to match predicate, or default value is none match	
	void			* (*last)				(CLQ_COLLECTION *src, PREDICATE, void *default_value);			//LAST - Gets the last value to match the predicate, or default value if none match	
	void			* (*max_element)		(CLQ_COLLECTION *src, int TRANSFORM);							//MAX-ELEMENT - Gets the element with the max value after transforming each value in sequence
	void			* (*min_element)		(CLQ_COLLECTION *src, int TRANSFORM);							//MIN-ELEMENT - Gets the element with the min value after transforming each value in sequence	
	void			* (*single)				(CLQ_COLLECTION *src, PREDICATE, void *default_value);			//SINGLE - Gets the only value to match the predicate, or default value if more than one match
	CLQ_COLLECTION	* (*concat)				(CLQ_COLLECTION *src, CLQ_COLLECTION *second);					//CONCAT - Joins 2 things together
	CLQ_COLLECTION	* (*default_if_empty)	(CLQ_COLLECTION *src, void *default_value);						//DEFAULT-IF-EMPTY - Returns either the sequence or a new sequence containing the default value if empty
	CLQ_COLLECTION	* (*distinct)			(CLQ_COLLECTION *src, EQ_COMPARITOR);							//DISTINCT - Returns the distinct elements in the sequence matching comparitor
	CLQ_COLLECTION	* (*except)				(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR);	//EXCEPT - Returns the set different using provided comparitor
	CLQ_COLLECTION	* (*set_intersect)		(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR);	//INTERSET - Performs set interst section on both seqeunces
	CLQ_COLLECTION	* (*reverse)			(CLQ_COLLECTION *src);											//REVERSE - Reverses the order of the elements in the underlying representation
	CLQ_COLLECTION	* (*skip)				(CLQ_COLLECTION *src, int count);								//SKIP - Gets a sequence missing the first count values
	CLQ_COLLECTION	* (*skip_while)			(CLQ_COLLECTION *src, PREDICATE);								//SKIP-WHILE - Gets a sequence missing the first number of items that match the predicate
	CLQ_COLLECTION	* (*take)				(CLQ_COLLECTION *src, int count);								//TAKE - Gets a sequence containing the first count values
	CLQ_COLLECTION	* (*take_while)			(CLQ_COLLECTION *src, PREDICATE);								//TAKE-WHILE - Gets a sequence containing the first number of items that match the predicate
	CLQ_COLLECTION	* (*set_union)			(CLQ_COLLECTION *src, CLQ_COLLECTION *second, EQ_COMPARITOR);	//UNION - Gets the set union of the 2 sequences
	CLQ_COLLECTION	* (*where)				(CLQ_COLLECTION *src, INDEX_PREDICATE);							//WHERE - Gets the values that match the predicate taking into account the index

	//MAYBE
	//CLQ_COLLECTION	(*cast)				(CLQ_COLLECTION *src, clinq_type dest);							//CAST - Transforms the underlying representation from one type to another.
	//int				(*eqauls)			(CLQ_COLLECTION *src, CLQ_COLLECTION *another);					//EQUALS - Return true is the 2 

} clq_collection_t;

#endif