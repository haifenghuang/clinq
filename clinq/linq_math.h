// CLINQ
// Defines the LINQ operations returning a mathematical calulcated value

#ifndef CLINQ_LINQ_MATH_H
#define CLINQ_LINQ_MATH_H

#include "list.h"
#include "functions.h"

int		linq_max			(clq_list_t *data, int TRANSFORM);
int		linq_min			(clq_list_t *data, int TRANSFORM);

long	linq_sum			(clq_list_t *data, int TRANSFORM);
float	linq_average		(clq_list_t *data, int TRANSFORM);

void	*linq_max_element	(clq_list_t *data, int TRANSFORM);
void	*linq_min_element	(clq_list_t *data, int TRANSFORM);

#endif