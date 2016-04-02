#include <stdio.h>
#include <stdlib.h>

#include "LINQ.h"
#include "collection.h"

struct clq_collection
{
	clq_list_t	*data;

	int			(*insert)				(COLLECTION *src, void *element);						//INSERT - Add an item into the list ignoring duplicates
	int			(*insert_distinct)		(COLLECTION *src, int TRANSFORM,  void *element);		//INSERT-DISTINCT - Add an item in the collection, checking for duplicates
	int			(*delete)				(COLLECTION *src, FREE_FUNC);							//DELETE - Clears the entire collection
	int			(*delete_where)			(COLLECTION *src, PREDICATE, FREE_FUNC);				//DELETE-WHERE - Delete all items that match the predicate
	long		(*size)					(COLLECTION *src);										//SIZE - Returns the collection size

	int			(*all)					(COLLECTION *src, PREDICATE);							//ALL - Predicate returns true or false for each item.
	int			(*any)					(COLLECTION *src, PREDICATE);							//ANY - Predicate returns true of false for each item.
	int			(*contains)				(COLLECTION *src, void *element, COMPARITOR);			//CONTAINS - Checks if object contains the specific element, with the given comparitor
	int			(*count)				(COLLECTION *src, PREDICATE);							//COUNT - The number of items that match the given predicate
	int			(*max_value)			(COLLECTION *src, int TRANSFORM);						//MAX - Gets the max value after transforming each value in sequence
	int			(*min_value)			(COLLECTION *src, int TRANSFORM);						//MIN - Gets the min value after transforming each value in sequence	
	long		(*sum)					(COLLECTION *src, int TRANSFORM);						//SUM - Gets the total value of the items in the collection
	long		(*long_count)			(COLLECTION *src, PREDICATE);							//LONG-COUNT - The number of items that match the given predicate, as a long
	float		(*average)				(COLLECTION *src, int TRANSFORM);						//AVERAGE - Transform turns non-numerical types into a float value.
	void		* (*element_at)			(COLLECTION *src, int index, void *default_value);		//ELEMENT-AT - Returns the element at the specified index, or defaul value if none-found
	void		* (*first)				(COLLECTION *src, PREDICATE, void *default_value);		//FIRST - Gets the first element to match predicate, or default value is none match	
	void		* (*last)				(COLLECTION *src, PREDICATE, void *default_value);		//LAST - Gets the last value to match the predicate, or default value if none match	
	void		* (*max_element)		(COLLECTION *src, int TRANSFORM);						//MAX-ELEMENT - Gets the element with the max value after transforming each value in sequence
	void		* (*min_element)		(COLLECTION *src, int TRANSFORM);						//MIN-ELEMENT - Gets the element with the min value after transforming each value in sequence	
	void		* (*single)				(COLLECTION *src, PREDICATE, void *default_value);		//SINGLE - Gets the only value to match the predicate, or default value if more than one match
	COLLECTION	* (*concat)				(COLLECTION *src, COLLECTION *second);					//CONCAT - Joins 2 things together
	COLLECTION	* (*default_if_empty)	(COLLECTION *src, void *default_value);					//DEFAULT-IF-EMPTY - Returns either the sequence or a new sequence containing the default value if empty
	COLLECTION	* (*distinct)			(COLLECTION *src, EQ_COMPARITOR);						//DISTINCT - Returns the distinct elements in the sequence matching comparitor
	COLLECTION	* (*except)				(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);	//EXCEPT - Returns the set different using provided comparitor
	COLLECTION	* (*set_intersect)		(COLLECTION *src, COLLECTION *second, EQ_COMPARITOR);	//INTERSET - Performs set interst section on both seqeunces
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

};



clq_collection_t *clq_create()
{
	clq_collection_t *collection = malloc(sizeof(clq_collection_t));
	if (!collection) { return NULL; }

	 collection->data = clq_list_create();

	//Full out the functions of the collection
	collection->insert = clq_list_insert;
	collection->insert_distinct = clq_list_insert_distinct;
	collection->delete = clq_list_delete;
	collection->delete_where = clq_list_delete_where;
	collection->size = clq_list_size;

	collection->all = linq_all;
	collection->any = linq_any;
	collection->contains = linq_contains;

	collection->count = linq_count;
	collection->max_value = linq_max;
	collection->min_value = linq_min;

	collection->sum = linq_sum;
	collection->long_count = linq_long_count;

	collection->average = linq_average;

	collection->element_at = linq_element_at;
	collection->first = linq_first;
	collection->last = linq_last;
	collection->max_element = linq_max_element;
	collection->min_element = linq_min_element;
	collection->single = linq_single;

	collection->concat = linq_concat;
	collection->default_if_empty = linq_default_if_empty;
	collection->distinct = linq_distinct;
	collection->except = linq_except;
	collection->set_intersect = linq_intersect;
	collection->reverse = linq_reverse;
	collection->skip = linq_skip;
	collection->skip_while = linq_skip_while;
	collection->take = linq_take;
	collection->take_while = linq_take_while;
	collection->set_union = linq_union;
	collection->where = linq_where;
	

	return collection;
}


void clq_destory(clq_collection_t *collection)
{
	if (collection)
	{
		//Free the other sections here....

		clq_list_destory(collection->data);
		free(collection);
	}
}