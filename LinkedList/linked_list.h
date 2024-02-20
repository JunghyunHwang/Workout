#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define FALSE (0)
#define TRUE !(FALSE)

typedef struct node {
    int value;
    struct node* next;
} node_t;

void insert_front(node_t** pphead, int value);

void insert_back(node_t** pphead, int value);

void insert_sorted(node_t** pphead, int value);

void delete_first(node_t** pphead);

void delete_last(node_t** pphead);

int delete_by_value(node_t** pphead, int value);

int find_by_value(node_t* phead, int value);

void print_node(node_t** phead);

void destroy(node_t** phead);

#endif /* LINKED_LIST_H */
