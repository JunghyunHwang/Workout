#ifndef LINKED_LIST_TEST_H
#define LINKED_LIST_TEST_H

#define MIN 1
#define MAX 100
#define DATA_SIZE 10

void test_insert_front(node_t* head);

void test_insert_back(node_t* head);

void test_insert_sorted(node_t* head);

void test_delete_first(node_t* head);

void test_delete_last(node_t* head);

void test_delete_by_value(node_t* head);

void test_find_by_value(node_t* head);

void test_delete_by_value(node_t* head);

void start_test(void);

#endif /* LINKED_LIST_TEST_H */
