// CLINQ
// Defines the LINQ operations returning a mathematical calulcated value

#ifndef CLINQ_LINQ_MATH_H
#define CLINQ_LINQ_MATH_H

#include "darray.h"
#include "functions.h"

int		linq_max			(darray_t *data, int TRANSFORM);
int		linq_min			(darray_t *data, int TRANSFORM);

long	linq_sum			(darray_t *data, int TRANSFORM);
float	linq_average		(darray_t *data, int TRANSFORM);

void	*linq_max_element	(darray_t *data, int TRANSFORM);
void	*linq_min_element	(darray_t *data, int TRANSFORM);

#endif