// CLINQ
// A linked-list implementation supporting LINQ functions
#ifndef CLINQ_LIST_H
#define CLINQ_LIST_H

typedef struct clq_list clq_list_t;

clq_list_t *clq_list_create();
void clq_list_destory(clq_list_t *list);

#endif