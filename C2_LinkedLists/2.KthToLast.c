#include <stdio.h>
#include "../lib/list_int.h"

int print_kth_to_last(list_int_t *, int);
list_int_t * kth_to_last(list_int_t *, int);
list_int_t * rec_fn(list_int_t *, int, int);

int main(void) {
    list_int_t * h = NULL;
    list_int_t * elm = NULL;
    h = append(h, 8);
    h = append(h, 7);
    h = append(h, 6);
    h = append(h, 5);
    h = append(h, 4);
    h = append(h, 3);
    h = append(h, 2);
    h = append(h, 1);
    h = append(h, 0);

    // print_list(h);
    // print_kth_to_last(h, 3);

    elm = kth_to_last(h, 3);
    printf("%d\n", elm->v);

    return 0;
}

int print_kth_to_last(list_int_t * h, int k) {
    printf("CALL\n");
    int next_pos, this_pos;
    if(h == NULL)
        return 0;
    else {
        next_pos = print_kth_to_last(h->next, k);
        this_pos = next_pos + 1;
        if(k == this_pos) {
            printf("%dth from last element: %d\n", k, h->v);
            return k;
        } else {
            return this_pos;
        }
    }
}

list_int_t * kth_to_last(list_int_t * h, int k) {
    int i = 0;
    return rec_fn(h, k, i);
}

list_int_t * rec_fn(list_int_t * h, int k, int i) {
    list_int_t * r = NULL;
    int this_pos, next_pos;
    if(h == NULL)
        return NULL;
    else
        r = rec_fn(h, k, i);
        i++;
        if(i == k)
            return h;
        return r;        
}
