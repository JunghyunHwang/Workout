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

    // Randomly generate test data
    srand(time(NULL));

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        *p_used++ = rand() % MAX_NUM + MIN_NUM;
    }

    for (size_t i = 0; i < DATA_SIZE; ++i) {
        *p_unused++ = rand() % (MAX << 1) + MAX_NUM;
    }

    is_init = TRUE;

    test_insert_front();
    test_insert_back();
    test_insert_sorted();
    test_delete_first();
    test_delete_last();
    test_find_by_value();
}

void test_insert_front(void)
{
    assert(is_init);
    node_t* head = NULL;
    node_t* next = NULL;
    size_t i;

    for (i = 0; i < DATA_SIZE; ++i) {
        insert_front(&head, s_used_arr[i]);

        assert(head->value == s_used_arr[i]);
        assert(head->next == next);
        next = head;
    }

    destroy(&head);
    assert(head == NULL);
}

void test_insert_back(void)
{
    node_t* head = NULL;
    node_t* last = NULL;
    size_t i;

    insert_back(&head, s_used_arr[0]);
    last = head;
    assert(last->value == s_used_arr[0]);
    assert(last->next == NULL);

    for (i = 1; i < DATA_SIZE; ++i) {
        insert_back(&head, s_used_arr[i]);
        last = last->next;
        assert(last != NULL);
        assert(last->value == s_used_arr[i]);
        assert(last->next == NULL);
    }

    destroy(&head);
    assert(head == NULL);
}

void test_insert_sorted(void)
{
    node_t* head = NULL;
    node_t* p_curr;
    node_t* p_prev;
    size_t i;

    for (i = 0; i < DATA_SIZE; ++i) {
        insert_sorted(&head, s_used_arr[i]);
    }

    p_curr = head->next;
    p_prev = head;

    while (p_curr != NULL) {
        assert(p_prev->value <= p_curr->value);

        p_prev = p_curr;
        p_curr = p_curr->next;
    }

    destroy(&head);
    assert(head == NULL);
}

void test_delete_first(void)
{

}

void test_delete_last(void)
{

}

void test_delete_by_value(void)
{
    node_t* head = NULL;
    size_t i;

    for (i = 0; i < DATA_SIZE; ++i) {
        insert_sorted(&head, s_used_arr[i]);
    }
    
    assert(!delete_by_value(&head, -1));

    assert(delete_by_value(&head, 3));
    assert(!delete_by_value(&head, 3));

    assert(delete_by_value(&head, 2));
    assert(!delete_by_value(&head, 2));

    assert(delete_by_value(&head, 5));
    assert(!delete_by_value(&head, 5));

    destroy(&head);
    assert(head == NULL);
}

void test_find_by_value(void)
{

}
