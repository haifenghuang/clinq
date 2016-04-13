#include <stdlib.h>
#include <limits.h>

#include "LINQ.h"
#include "darray.h"

// BOOL Functions
// ---------------
int linq_all(darray_t *src, PREDICATE)
{
	for (int i = 0; i < src->size; i++)
	{
		if (!predicate(src->data[i])) { return 0; }
	}
	return 1;
}

int linq_any(darray_t *src, PREDICATE)
{
	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i])) { return 1; }
	}
	return 0;
}

int linq_contains(darray_t *src, void *element, EQ_COMPARITOR)
{
	for (int i = 0; i < src->size; i++)
	{
		if (equality_comparitor(element, src->data[i])) { return 1; }
	}
	return 0;
}

// DATA Functions
// --------------
CLQ_COLLECTION *linq_concat(darray_t *src, darray_t *second)
{
	CLQ_COLLECTION *newCol = clq_create();
	if (!newCol) { return NULL; }

	for (int i = 0; i < src->size; i++)
	{
		if (!clq_insert(newCol, src->data[i]))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	for (int i = 0; i < src->size; i++)
	{
		if (!clq_insert(newCol, second->data[i]))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	return newCol;
}

CLQ_COLLECTION	*linq_default_if_empty(darray_t *src, void *default_value)
{
	CLQ_COLLECTION *newCol = NULL;

	if (clq_size(src) == 0)
	{
		newCol = clq_create();
		if (!newCol) { return NULL; }

		if (!clq_insert(newCol, default_value))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	return (newCol) ? newCol : src;
}

CLQ_COLLECTION	*linq_reverse(darray_t *src)
{
	for (int i = 0; i < (src->size / 2); i++)
	{
		void *temp = src->data[i];
		src->data[i] = src->data[(src->size - i)];
		src->data[(src->size - i)] = temp;
	}

	return src;
}


CLQ_COLLECTION *linq_skip(darray_t *src, int count)
{
	CLQ_COLLECTION *newCol = clq_create();
	if (!newCol) { return NULL; }

	for (int i = count; i < src->size; i++)
	{
		if (!clq_insert(newCol, src->data[i]))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	return newCol;
}

CLQ_COLLECTION *linq_skip_while(darray_t *src, PREDICATE)
{
	int index = 0;
	CLQ_COLLECTION *newCol = clq_create();
	if (!newCol) { return NULL; }

	while (predicate(src->data[index]) && index < src->size)
	{
		index++;
	}

	for (int i = index; i < src->size; i++)
	{
		if (!clq_insert(newCol, src->data[i]))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	return newCol;
}


CLQ_COLLECTION *linq_take(darray_t *src, int count)
{
	int itemCount = (count <= src->size) ? count : src->size;
	CLQ_COLLECTION *newCol = clq_create();
	if (!newCol) { return NULL; }

	for (int i = 0; i < itemCount; i++)
	{
		if (!clq_insert(newCol, src->data[i]))
		{
			clq_destory(newCol);
			return NULL;
		}
	}

	return newCol;
}

CLQ_COLLECTION	*linq_take_while(darray_t *src, PREDICATE)
{
	CLQ_COLLECTION *newCol = clq_create();
	if (!newCol) { return NULL; }

	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i]))
		{
			if (!clq_insert(newCol, src->data[i]))
			{
				clq_destory(newCol);
				return NULL;
			}
		}
		else { break; }
	}

	return newCol;
}

// MATH Functions
// ---------------
int	linq_max(darray_t *src, int TRANSFORM)
{
	int maxVal = INT_MIN;

	for (int i = 0; i < src->size; i++)
	{
		int elementVal = transform(src->data[i]);
		if (elementVal > maxVal) { maxVal = elementVal; }
	}

	return maxVal;
}

int	linq_min(darray_t *src, int TRANSFORM)
{
	int minVal = INT_MAX;

	for (int i = 0; i < src->size; i++)
	{
		int elementVal = transform(src->data[i]);
		if (elementVal < minVal) { minVal = elementVal; }
	}

	return minVal;
}


long linq_sum(darray_t *src, int TRANSFORM)
{
	long sum = 0L;

	for (int i = 0; i < src->size; i++)
	{
		sum += transform(src->data[i]);
	}

	return sum;
}

float linq_average(darray_t *src, int TRANSFORM)
{
	return (float)linq_sum(src, transform) / (float)src->size;
}


void *linq_max_element(darray_t *src, int TRANSFORM)
{
	int maxVal = INT_MIN;
	void *maxEle = NULL;

	for (int i = 0; i < src->size; i++)
	{
		int elementVal = transform(src->data[i]);

		if (elementVal > maxVal)
		{
			maxVal = elementVal;
			maxEle = src->data[i];
		}
	}

	return maxEle;
}

void *linq_min_element(darray_t *src, int TRANSFORM)
{
	int minVal = INT_MAX;
	void * minEle = NULL;

	for (int i = 0; i < src->size; i++)
	{
		int elementVal = transform(src->data[i]);

		if (elementVal < minVal)
		{
			minVal = elementVal;
			minEle = src->data[i];
		}
	}

	return minEle;
}

// QUERY Functions
//---------------
int	linq_count(darray_t *src, PREDICATE)
{
	int count = 0;

	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i])) { count++; }
	}

	return count;
}

long linq_long_count(darray_t *src, PREDICATE)
{
	long count = 0L;

	for (long i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i])) { count++; }
	}

	return count;
}

void *linq_element_at(darray_t *src, int index, void *default_value)
{
	return (index <= src->size) ? src->data[index] : default_value;
}


void *linq_first(darray_t *src, PREDICATE, void *default_value)
{
	int index = 0;
	while (!predicate(src->data[index]) && index < src->size)
	{
		index++;
	}

	return (index < src->size) ? src->data[index] : default_value;
}

void *linq_last(darray_t *src, PREDICATE, void *default_value)
{
	void *element = NULL;

	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i])) { element = src->data[i]; }
	}

	return element;
}

void *linq_single(darray_t *src, PREDICATE, void *default_value)
{
	int		numFound = 0;
	void	*element = NULL;

	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i]))
		{
			element = src->data[i];
			numFound++;
		}
	}

	return (numFound == 1) ? element : default_value;
}


CLQ_COLLECTION *linq_where(darray_t *src, INDEX_PREDICATE)
{
	CLQ_COLLECTION *newCol = clq_create();
	if (!newCol) { return NULL; }

	for (int i = 0; i < src->size; i++)
	{
		if (predicate(src->data[i], i))
		{
			if (!clq_insert(newCol, src->data[i]))
			{
				clq_destory(newCol);
				return NULL;
			}
		}
	}

	return newCol;
}


// SET Functions
// ---------------
CLQ_COLLECTION *linq_distinct(darray_t *src, EQ_COMPARITOR) { return NULL; }
CLQ_COLLECTION *linq_except(darray_t *src, darray_t *second, EQ_COMPARITOR) { return NULL; }
CLQ_COLLECTION *linq_intersect(darray_t *src, darray_t *second, EQ_COMPARITOR) { return NULL; }
CLQ_COLLECTION *linq_union(darray_t *src, darray_t *second, EQ_COMPARITOR) { return NULL; }
