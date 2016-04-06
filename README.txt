CLINQ 
A C simple (WIP, but functional) library providing a generic data structure with LINQ-like methods.


BUILDING:
Use provided Visual Studio solution.

USAGE:
Add clinq.lib to linker options
Including "clinq.h" (you may need to also need "functions.h", if you don't setup include directories)

"functions.h" contains all functions available via clinq.
Preprocessors define the types of function pointers the methods are expecting.
"clinq.h" macro access to clinq functions -> prefix CLQ_[FUNCTION]: i.e CLQ_SKIP_WHILE( ... ); 


TODO:
- Implement remaining 'set' functions
- Cleanup much of internals
- Test
- Makefile
- Library header generate
- Docs
- GCC / Linux port
