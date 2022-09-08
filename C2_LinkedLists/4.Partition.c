#include <stdio.h>
#include <stdlib.h>
#include "../lib/list_int.h"

list_int_t * partition(list_int_t *, int);

int main(void) {
    list_int_t * h = NULL;

    h = append(h, 3);
    h = append(h, 5);
    h = append(h, 8);
    h = append(h, 5);
    h = append(h, 10);
    h = append(h, 2);
    h = append(h, 1);

    print_list(h);
    h = partition(h, 5);
    print_list(h);

    return 0;
}


// This solution is different from the one in the book, as it operates in place, whithout the
// necessity of creating two new lists for the partitions.
list_int_t * partition(list_int_t * h, int part) {
    list_int_t * l, * r;
    int len, rp_size, lp_size, i, tmp;

    len = 0; rp_size = 0;
    r = h;
    while(r != NULL) {
        if(r->v >= part)
            rp_size++;
        len++;
        r = r->next;
    }
    lp_size = len - rp_size;

    r = h;
    i = 0;
    while(i < lp_size) {
        r = r->next;
        i++;
    }
    
    l = h;
    while(r != NULL) {
        while(l->v < part)
            l = l->next;
        while(r->v >= part)
            r = r->next;

        tmp = l->v;
        l->v = r->v;
        r->v = tmp;

        l = l->next;
        r = r->next;
    }

    return h;
}
