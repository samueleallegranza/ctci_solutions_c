#include <stdio.h>
#include <stdlib.h>
#include "../lib/list_int.h"
#include "../lib/uthash/src/uthash.h"

// for hash table use
typedef struct hash_table_s{
    int id;                 // key
    UT_hash_handle hh;      // makes this structure hashable
} hash_table_t;

list_int_t * remove_dups_sll(list_int_t *);
list_int_t * remove_dups_ht(list_int_t *);
list_int_t * remove_dups_inplace(list_int_t *);
void ht_delete_all(hash_table_t *);


int main(void) {
    list_int_t * h = NULL;
    h = append(h, 1);
    h = append(h, 2);
    h = append(h, 3);
    h = append(h, 1);
    h = append(h, 3);
    h = append(h, 2);
    h = append(h, 4);
    h = append(h, 1);

    print_list(h);
    h = remove_dups_ht(h);
    print_list(h);

    return 0;
}

// Solution that implements a secondary singly linked list
list_int_t * remove_dups_sll(list_int_t * h) {
    list_int_t * new = NULL;
    list_int_t * p;

    p = h;
    while(p != NULL) {
        // search value in new
        if(find_value(new, p->v) == -1) {
            new = append(new, p->v);
        }
        p = p->next;
    }

    // deallocation of old list
    freelist(h);

    return new;
}

// Solution that implements hashtable
list_int_t * remove_dups_ht(list_int_t * h) {
    hash_table_t * ht = NULL;
    hash_table_t * found, * ht_elem;
    list_int_t * prev, * x;
    int i;

    // Check if list is not empty.
    if(h == NULL) {
        return NULL; // Function execution ends here!
    }

    // The head can't be a repetition, so we add it in the hash table (which is empty)
    ht_elem = malloc(sizeof(hash_table_t));
    ht_elem->id = h->v;
    HASH_ADD_INT(ht, id, ht_elem);  /* id: name of key field */

    // We scan the list with two pointers 'x' (current list elem.) and 'prev' (previous list elem.)
    prev = h;
    x = h->next;
    i = 0;
    while(x != NULL) {
        // Check if value is already in the hashtable
        HASH_FIND_INT(ht, &(x->v), found);
        if(found == NULL) {
            // Value not found in the hash table, so we add it
            ht_elem = malloc(sizeof(hash_table_t));
            ht_elem->id = x->v;
            HASH_ADD_INT(ht, id, ht_elem);  /* id: name of key field */
            // Advance both 'x' and 'prev'
            prev = prev->next;
            x = x->next;
        } else {
            // Remove the element from the list
            prev->next = x->next;
            free(x);
            // Advance only 'x', as 'prev' is pointing correctly
            x = prev->next;
        }
        i++;
    }

    // free the hash table contents
    ht_delete_all(ht);

    return h;
}

// Solution that O(1) space and O(N^2) time
list_int_t * remove_dups_inplace(list_int_t * h) {
    // to do
    return h;
}


void ht_delete_all(hash_table_t * ht) {
    hash_table_t *current_entry, *tmp;

    HASH_ITER(hh, ht, current_entry, tmp) {
        HASH_DEL(ht, current_entry);  /* delete; entry advances to next */
        free(current_entry);          /* optional- if you want to free  */
    }
}

