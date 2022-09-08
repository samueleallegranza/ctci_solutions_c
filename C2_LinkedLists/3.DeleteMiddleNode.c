/*
    Note: This solution has to be improved
*/

#include <stdio.h>
#include <stdlib.h>
#include "../lib/list_int.h"

void delete_middle_node_head(list_int_t *);
void delete_middle_node(list_int_t *);

int main(void) {
    list_int_t * x = NULL;

    x = append(x, 1);
    x = append(x, 2);
    x = append(x, 3);
    x = append(x, 4);
    x = append(x, 5);
    x = append(x, 6);

    print_list(x);
    printf("To be deleted: [%d]\n", x->next->next->v);
    delete_middle_node(x->next->next);
    print_list(x);

    return 0;
}

// Deletes the middle point of the list given the head of it
void delete_middle_node_head(list_int_t * h) {
    list_int_t * runner, * follower;
    runner = h; follower = NULL;

    while(runner->next != NULL) {
        if(runner->next->next != NULL) {
            runner = runner->next->next;
            // Follower must be an element late to be able to delete the middle node!
            if(follower == NULL)
                follower = h;
            else 
                follower = follower->next;
        } else {
            runner = runner->next;
        }
    }

    // Delete the middle node (runner used as temporary pointer)
    runner = follower->next;
    follower->next = follower->next->next;
    free(runner);
}

// Delete the node passed as an argument, supposing it is not the first or last element of the list
void delete_middle_node(list_int_t * d) {
    list_int_t * front, * back;
    
    front = d->next;
    back = d;
    while(front->next != NULL) {
        back->v = front->v;
        front = front->next;
        back = back->next;
    }

    // Delete last node;
    printf("%d\n", back->v);
    back->next = NULL;
    free(front);
}
