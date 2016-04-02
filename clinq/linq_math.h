// CLINQ
// Defines the LINQ operations returning a mathematical calulcated value

#ifndef CLINQ_LINQ_MATH_H
#define CLINQ_LINQ_MATH_H

#include "list.h"
#include "functions.h"

int		linq_max			(COLLECTION *data, int TRANSFORM);
int		linq_min			(COLLECTION *data, int TRANSFORM);

long	linq_sum			(COLLECTION *data, int TRANSFORM);
long	linq_long_count		(COLLECTION *data, PREDICATE);
float	linq_average		(COLLECTION *data, int TRANSFORM);

void	*linq_max_element	(COLLECTION *data, int TRANSFORM);
void	*linq_min_element	(COLLECTION *data, int TRANSFORM);

#endif