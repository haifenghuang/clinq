CLINQ 
A C simple (WIP, but functional) library providing a generic data structure with LINQ-like methods.
Requires C99 standard.


BUILDING:

- Visual Studio 2013 (or later)
	* Use provided solution.

- GCC
	* Use makefile provided


USAGE:
Add libclinq.lib to linker options
Including "clinq.h" (you may need to also need "functions.h", if you don't setup include directories)

"clinq.h" contains macros for all functions.

Preprocessors define the types of function pointers the methods are expecting.
"clinq.h" macro access to clinq functions -> prefix CLQ_[FUNCTION]: i.e CLQ_SKIP_WHILE( ... ); 

EXAMPLE:

#include "/path/to/clinq.h"

// ...
int transform(void *obj) {
	return (int)obj;
}

int predicate(void *obj) {
	return (int)objA == 5;

// ...
CLQ_COLLECTION *collection = clq_create();

for(int i = 0; i < 10; i++) {
    CLQ_INSERT(collection, i);
}

printf("We have a collection of size: %ld\n", CLQ_SIZE(collection));

printf("Collection Sum: %ld\n", CLQ_SUM(collection, transform));

//Delete all items matching out predicate function above (or where i == 5)
CLQ_DELETE_WHERE(collection, predicate);


// ...
//Clear the list, specifing a free function, incase our collection has malloc'd data
CLQ_DELETE(collection, NULL); 
clq_destory(collection);

// ...


TODO:
- Implement remaining 'set' functions
- Test
- Library header generate
- Docs