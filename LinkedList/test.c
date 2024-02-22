#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "test.h"
#include "linked_list.h"

static int s_used_arr[DATA_SIZE];
static int s_unused_arr[DATA_SIZE];

static int is_init = FALSE;

void start_test(void)
{
    const size_t MIN_NUM = MIN;
    const size_t MAX_NUM = MAX;
    int* p_used = s_used_arr;
    int* p_unused = s_unused_arr;
    node_t* head;

    // Randomly generate test data
    srand(time(NULL));

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        *p_used++ = rand() % MAX_NUM + MIN_NUM;
    }

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        *p_unused++ = rand() % (MAX << 1) + MAX_NUM;
    }

    is_init = TRUE;

    head = NULL;
    test_insert_front(head);
    destroy(&head);

    assert(head == NULL);
    test_insert_back(head);
    destroy(&head);

    assert(head == NULL);
    test_insert_sorted(head);
    destroy(&head);

    assert(head == NULL);
    test_find_by_value(head);
    destroy(&head);

    assert(head == NULL);
    test_delete_first(head);
    destroy(&head);

    assert(head == NULL);
    test_delete_last(head);
    destroy(&head);    
}

void test_insert_front(node_t* head)
{
    assert(is_init);
    node_t* next = NULL;
    int* p_used = s_used_arr;
    size_t i;

    for (i = 0; i < DATA_SIZE; ++i) {
        insert_front(&head, *p_used);

        assert(head->value == *p_used);
        assert(head->next == next);

        next = head;
        ++p_used;
    }
}

void test_insert_back(node_t* head)
{
    assert(is_init);
    node_t* last = NULL;
    int* p_used = s_used_arr;
    size_t i;

    insert_back(&head, *p_used);
    last = head;
    assert(last->value == *p_used);
    assert(last->next == NULL);

    for (i = 1; i < DATA_SIZE; ++i) {
        insert_back(&head, *p_used);
        last = last->next;

        assert(last != NULL);
        assert(last->value == *p_used);
        assert(last->next == NULL);

        ++p_used;
    }
}

void test_insert_sorted(node_t* head)
{
    assert(is_init);
    node_t* p_curr;
    node_t* p_prev;
    int* p_used = s_used_arr;
    size_t i;

    for (i = 0; i < DATA_SIZE; ++i) {
        insert_sorted(&head, *p_used++);
    }

    p_curr = head->next;
    p_prev = head;

    while (p_curr != NULL) {
        assert(p_prev->value <= p_curr->value);

        p_prev = p_curr;
        p_curr = p_curr->next;
    }
}


void test_find_by_value(node_t* head)
{
    assert(is_init);
    int* p_used = s_used_arr;
    int* p_unused = s_unused_arr;
    size_t i;

    for (i = 0; i < DATA_SIZE; ++i) {
        insert_front(&head, *p_used++);
    }

    p_used = s_used_arr;

    for (i = 0; i < DATA_SIZE; ++i) {
        assert(find_by_value(&head, *p_used++));
        assert(!find_by_value(&head, *p_unused++));
    }
}

void test_delete_first(node_t* head)
{
    assert(is_init);
    node_t* next;
    int* p_used = s_used_arr;
    size_t i;

    for (i = 0; i < DATA_SIZE; ++i) {
        insert_front(&head, *p_used++);
    }

    next = head->next;
    for (i = 0; i < DATA_SIZE; ++i) {
        delete_first(&head);
        assert(head == next);
        next = head->next;
    }

    assert(head == NULL);
}

void test_delete_last(node_t* head)
{
    assert(is_init);

    int* p_used = s_used_arr;
    size_t i;

    for (i = 0; i < DATA_SIZE; ++i) {
        insert_front(&head, *p_used++);
    }

    --p_used;

    for (i = DATA_SIZE - 1; i < DATA_SIZE; ++i) {
        delete_last(&head);
        assert(!find_by_value(&head, *p_used--));
    }
}

void test_delete_by_value(node_t* head)
{
    assert(is_init);
    int* p_used = s_used_arr;
    int* p_unused = s_used_arr;
    size_t i;

    for (i = 0; i < DATA_SIZE; ++i) {
        insert_front(&head, *p_used++);
    }

    p_used = s_used_arr;
    for (i = 0; i < DATA_SIZE; ++i) {
        assert(delete_by_value(&head, *p_used++));
    }

    p_used = s_used_arr;
    for (i = 0; i < DATA_SIZE; ++i) {
        insert_front(&head, *p_used++);
    }

    for (i = 0; i < DATA_SIZE; ++i) {
        assert(!delete_by_value(&head, *p_unused++));
    }
}
