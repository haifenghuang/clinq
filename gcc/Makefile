#Clinq Makefile

CC=gcc
CFLAGS = -W -Wall -std=c99

#Clinq Lib
LIB_OUT=bin/libclinq.a
LIB_IN=obj/darray.o obj/linq.o obj/darray_dispatcher.o



#Default Target
all : dirs $(LIB_OUT) cphead

#Make into lib file
$(LIB_OUT) : $(LIB_IN)
		ar rcs $@ $^

obj/%.o : ../src/%.c
		$(CC) $(CFLAGS) -c -o $@ $^

#Make directories if needed
dirs :
		@mkdir -p obj/
		@mkdir -p bin/clinq/

#Copies the 2 header files required for the library
cphead:
		@echo "Copying CLINQ headers..."
		@cp ../src/clinq.h bin/clinq/clinq.h
		@cp ../src/functions.h bin/clinq/functions.h

#Others
.PHONY: clean fullclean dirs cphead
