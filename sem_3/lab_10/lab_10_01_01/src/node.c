#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "point.h"

list_t *node_create(void *element)
{
    list_t *list = malloc(sizeof(*list));
    if (!list)
        return NULL;
    list->next = NULL;
    list->element = element;
    return list;
}

void node_destroy(list_t *node)
{
    free(node);
}

void fprint_node(FILE *file, const list_t *node)
{
    fprintf(file, "%.2lf,%.2lf", ((point_t *)node->element)->x, ((point_t *)node->element)->y);
}
