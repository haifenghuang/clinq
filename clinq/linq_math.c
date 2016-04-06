#include <stdio.h>
#include <limits.h>

#include "linq_math.h"


int	linq_max(clq_list_t *src, int TRANSFORM)
{ 
	int maxVal = INT_MIN;

	for (int i = 0; i < src->size; i++)
	{
		int elementVal = transform(src->data[i]);
		if (elementVal > maxVal) { maxVal = elementVal; }
	}

	return maxVal;
}

int	linq_min(clq_list_t *src, int TRANSFORM) 
{ 
	int minVal = INT_MAX;

	for (int i = 0; i < src->size; i++)
	{
		int elementVal = transform(src->data[i]);
		if (elementVal < minVal) { minVal = elementVal; }
	}

	return minVal;
}


long linq_sum(clq_list_t *src, int TRANSFORM)
{ 
	long sum = 0L;

	for (int i = 0; i < src->size; i++)
	{
		sum += transform(src->data[i]);
	}

	return sum;
}

float linq_average(clq_list_t *src, int TRANSFORM)
{ 
	return (float)linq_sum(src, transform) / (float)src->size;
}


void *linq_max_element(clq_list_t *src, int TRANSFORM)
{ 
	int maxVal		= INT_MIN;
	void *maxEle	= NULL;

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

void *linq_min_element(clq_list_t *src, int TRANSFORM)
{ 
	int minVal		= INT_MAX;
	void * minEle	= NULL;

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