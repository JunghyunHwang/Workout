#ifndef LINKED_LIST_TEST_H
#define LINKED_LIST_TEST_H

#define MIN 1
#define MAX 100
#define DATA_SIZE 10

void test_insert_front(void);

void test_insert_back(void);

void test_insert_sorted(void);

void test_delete_first(void);

void test_delete_last(void);

void test_delete_by_value(void);

void test_find_by_value(void);

void test_delete_by_value(void);

/* Utiliy */
void start_test(void);

int get_random_num(int min, int max);

#endif /* LINKED_LIST_TEST_H */
