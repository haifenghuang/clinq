// CLINQ
// Contains definitions of all the CLINQ types supported

#ifndef CLINQ_TYPES_H
#define CLINQ_TYPES_H

#include "array.h"
#include "dict.h"
#include "list.h"

typedef struct c_array carr_t;
typedef struct c_list clist_t;
typedef struct c_dict cdict_t;

typedef enum clinq_type {
	ARRAY,
	LIST,
	DICTIONARY
} clinq_type;


typedef struct cobj
{
	void *data;
	clinq_type type;

	// TODO  - Refactor some of this into MACROS / #DEFINES :O

	long (*sum)(struct cobj *src);																							//SUM - NO PARAMS
	int (*all) (struct cobj *src, int(*predicate)(void *obj));																//ALL - Predicate returns true or false for each item.
	int(*any) (struct cobj *src, int(*predicate)(void *obj));																//ANY - Predicate returns true of false for each item.
	float(*average) (struct cobj *src, int(transform)(void *obj));															//AVERAGE - Transform turns non-numerical types into a float value.
	struct cobj *(*concat) (struct cobj *src, void *dest);																	//CONCAT - Joins 2 things together
	int(*contains) (struct cobj *src, void *element, int(*comparitor)(void *element, void *obj));							//CONTAINS - Checks if object contains the specific element, with the given comparitor
	int(*count) (struct cobj *src, int(*predicate)(void *obj));																//COUNT - The number of items that match the given predicate
	struct cobj *(*default_if_empty) (struct cobj *src, void *default_value);												//DEFAULT-IF-EMPTY - Returns either the sequence or a new sequence containing the default value if empty
	struct cobj *(*distinct) (struct cobj *src, int(*equality_comparitor)(void *objA, void* objB));							//DISTINCT - Returns the distinct elements in the sequence matching comparitor
	void* (*element_at)(struct cobj *src, int index, void *default_value);													//ELEMENT-AT - Returns the element at the specified index, or defaul value if none-found
	struct cobj *(*except)(struct cobj *src, int(*equality_comparitor)(void *objA, void *objB));							//EXCEPT - Returns the set different using provided comparitor
	void *(*first)(struct cobj *src, int (*predicate)(void *obj), void *default_value);										//FIRST - Gets the first element to match predicate, or default value is none match
	struct cobj *(*set_intersect)(struct cobj *src, struct cobj *second, int(*comparitor)(void *objA, void *objB));			//INTERSET - Performs set interst section on both seqeunces
	void *(*last)(struct cobj *src, int(*predicate)(void *obj), void *default_value);										//LAST - Gets the last value to match the predicate, or default value if none match
	long (*long_count) (struct cobj *src, int(*predicate)(void *obj));														//LONG-COUNT - The number of items that match the given predicate, as a long
	void *(*max)(struct cobj *src, int(*transform)(void *obj));																//MAX - Gets the max value after transforming each value in sequence
	void *(*min)(struct cobj *src, int(*transform)(void *obj));																//MIN - Gets the min value after transforming each value in sequence
	struct cobj *(*reverse)(struct cobj *src);																				//REVERSE - Reverses the order of the elements in the underlying representation
	void *(*single)(struct cobj *src, int(*predicate)(void *obj), void *default_value);										//SINGLE - Gets the only value to match the predicate, or default value if more than one match
	struct cobj *(*skip)(struct cobj *src, int count);																		//SKIP - Gets a sequence missing the first count values
	struct cobj *(*skip_while)(struct cobj *src, int(*predicate)(void *obj));												//SKIP-WHILE - Gets a sequence missing the first number of items that match the predicate
	struct cobj *(*take)(struct cobj *src, int count);																		//TAKE - Gets a sequence containing the first count values
	struct cobj *(*take_while)(struct cobj *src, int(*predicate)(void *obj));												//TAKE-WHILE - Gets a sequence containing the first number of items that match the predicate
	struct cobj *(*set_union) (struct cobj *src, struct cobj *second, int(*equalilty_comparitor)(void *objA, void *objB));	//UNION - Gets the set union of the 2 sequences
	struct cobj *(*where)(struct cobj *src, int(*predicate)(void *obj, int index));											//WHERE - Gets the values that match the predicate taking into account the index


	//MAYBE
	//clinq_t (*cast)(struct cobj *src, clinq_type dest);				//CAST - Transforms the underlying representation from one type to another.
	//int(*eqauls)(struct cobj *src, struct cobj *another);				//EQUALS - Return true is the 2 

} clinq_t;


#endif