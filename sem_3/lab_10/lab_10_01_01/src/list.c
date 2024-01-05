#include "list.h"
#include "node.h"

#include <stdbool.h>
#include <stdlib.h>

list_t *find(list_t *head, const void *data, comparator_t dist_cmp)
{
    for (list_t *inode = head; inode; inode = inode->next)
        if (!dist_cmp(inode->element, data))
            return inode;
    
    return NULL;
}

void insert(list_t **head, list_t *elem, list_t *before)
{
    bool added = false;
    list_t *prev = NULL;
    if (!elem || !before || !head)
        return;

    for (list_t *inode = *head; inode && !added; inode = inode->next)
    {
        if (inode == before)
        {
            if (!prev)
            {
                elem->next = *head;
                *head = elem;
            }
            else
            {
                prev->next = elem;
                elem->next = inode;
            }
            added = true;
            inode = elem;
        }
        prev = inode;
    }
}


list_t *reverse(list_t *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    list_t *rev_head = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rev_head;
}

list_t *sort(list_t *head, comparator_t cmp)
{
    list_t *sorted_head = NULL;

    for (list_t *inode = head; inode;)
    {
        list_t *next_node = inode->next;
        sorted_insert(&sorted_head, inode, cmp);
        inode = next_node;
    }

    return sorted_head;
}

void sorted_insert(list_t **head, list_t *element, comparator_t cmp)
{
    list_t *prev = NULL;
    list_t *inode = NULL;
    
    for (inode = *head; inode && cmp(inode->element, element->element) <= 0; inode = inode->next)
        prev = inode;
    
    if (!prev)
    {
        element->next = *head;
        *head = element;
    }
    else
    {
        list_t *tmp_node = prev->next;
        prev->next = element;
        prev->next->next = tmp_node;
    }
}

void fprint_list(FILE *file, list_t *head)
{
    for (list_t *inode = head; inode; inode = inode->next)
    {
        fprint_node(file, inode);
        if (inode->next)
            fprintf(file, " ");
    }
    fprintf(file, "\n");
}

void free_list(list_t *head)
{
    for (list_t *inode = head; inode;)
    {
        list_t *tmp_node = inode->next;
        node_destroy(inode);
        inode = tmp_node;
    }
}
