#include "list.h"
#include "node.h"
#include "point.h"
#include "storage.h"

#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 4)
        return ERR_ARGS;
    
    err_t err = OK;
    list_t *head = NULL;
    point_t add_point = 
    {
        .x = 0, 
        .y = 0
    };
    points_t storage = 
    {
        .cnt = 0,
        .points = NULL
    };
    err = fread_storage_ex(argv[2], &storage);
    if (!err)
    {
        head = storage2list(&storage);
        if (!strcmp(argv[1], "r"))
            head = reverse(head);
        else if (!strcmp(argv[1], "s"))
            head = sort(head, points_cmp);
        else if (!strcmp(argv[1], "i") && argc == 5)
        {
            double dist;
            list_t *add_node = NULL;
            err = !err ? fread_insert_data(argv[3], &dist, &add_point) : err;
            err = !err ? ((!(add_node = node_create(&add_point))) ? ERR_DATA : OK) : err;
            if (!err)
            {
                list_t *before_node = find(head, &dist, dist_cmp);
                if (!before_node)
                {
                    node_destroy(add_node);
                    err = ERR_DATA;
                }
                
                if (!err)
                    insert(&head, add_node, before_node);
            }
        }
        else if (!err)
            err = ERR_ARGS;
    }
    
    if (!err)
    {
        FILE *file = fopen(argv[argc - 1], "w");
        if (file)
        {
            fprint_list(file, head);
            fclose(file);
        }
        else
            err = ERR_FILE;
    }

    points_destroy(&storage);
    free_list(head);
    return err;
}
