// CLINQ
// An array implementation supporting LINQ functions

#ifndef CLINQ_ARRAY_H
#define CLINQ_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct clq_array clq_array_t;


clq_collection_t *clq_array_create(int size);
void clq_array_destory(clq_collection_t *array);


#endif