CLINQ 
A C simple (WIP, but functional) library providing a generic data structure with LINQ-like methods.


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


TODO:
- Implement remaining 'set' functions
- Test
- Library header generate
- Docs