#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void insert_front(node_t** pphead, int val)
{
    node_t* new_node;
    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = val;
    new_node->next = *pphead;

    *pphead = new_node;
}

void insert_back(node_t** pphead, int val)
{
    node_t** pp = pphead;
    node_t* new_node;

    while (*pp != NULL) {
        pp = &(*pp)->next;
    }

    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = val;
    new_node->next = NULL;

    *pp = new_node;
}

void insert_sorted(node_t** pphead, int val)
{
    node_t** pp = pphead;
    node_t* new_node;

    while (*pp != NULL) {
        if ((*pp)->value > val) {
            break;
        }

        pp = &(*pp)->next;
    }

    new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = val;
    new_node->next = *pp;

    *pp = new_node;
}

void delete_first(node_t** pphead)
{
    node_t* second = (*pphead)->next;

    free(*pphead);
    *pphead = second;
}

void delete_last(node_t** pphead)
{
    node_t** pp = pphead;

    while ((*pp)->next != NULL) {
        pp = &(*pp)->next;
    }

    free(*pp);
    *pp = NULL;
}

int delete_by_value(node_t** pphead, int val)
{
    node_t** pp = pphead;

    while (*pp != NULL) {
        if ((*pp)->value == val) {
            node_t* next = (*pp)->next;
            free(*pp);
            *pp = next;

            return TRUE;
        }

        pp = &(*pp)->next;
    }

    return FALSE;
}

void print_node(node_t** pphead)
{
    node_t** pp = pphead;

    while (*pp != NULL) {
        printf("%d, ", (*pp)->value);

        pp = &(*pp)->next;
    }

    printf("\n");
}

void destroy(node_t** pphead)
{
    node_t** pp = pphead;

    while (*pp != NULL) {
        node_t* next = (*pp)->next;
        free(*pp);
        *pp = next;
    }
}
