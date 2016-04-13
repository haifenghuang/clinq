#ifndef CLINQ_DARRAY_H
#define CLINQ_DARRAY_H

#define DEFAULT_ARRAY_SIZE	16
#define ARRAY_GROW_FACTOR	2

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

#endif