#ifndef CLINQ_DARRAY_H
#define CLINQ_DARRAY_H

#define DEFAULT_ARRAY_SIZE	16
#define ARRAY_GROW_FACTOR	2

#include "functions.h"


typedef struct dynamic_array
{
	void	**data;
	long	size;
	long	array_size;
} darray_t;


//Creates a new Dyanmic Array
//Returns NULL if failed
darray_t *darray_create();

//Frees the memory associated with the dynamic array
//TODO - Free elements as well.
void darray_destory(darray_t *arr);

//Adds an element to the dynamic array
//If the array is full, it's attemped to be increased
//Returns 0 if failed
int darray_insert(darray_t *arr, void *element);

//Adds an element to the dynamic array if it's not already in it.
//If the array is full, it's attempted to be increased
//Returns 0 if failed.
int darray_insert_distinct(darray_t *arr, void *element, EQ_COMPARITOR);

//Clears the entire list using the free function.
int darray_clear(darray_t *arr, FREE_FUNC);

//Clears only the items that match the predicate using the free function.
int darray_delete_where(darray_t *src, PREDICATE, FREE_FUNC);

#endif