#include <stdio.h>
#include <stdlib.h>
#include "../lib/list_int.h"

list_int_t * sum_list(list_int_t *, list_int_t *);
list_int_t * sum_list_v2(list_int_t *, list_int_t *);
list_int_t * add_list(list_int_t *, list_int_t *, int);

int main(void) {
    list_int_t * n1 = NULL;
    list_int_t * n2 = NULL;
    list_int_t * s = NULL;

    n1 = append(n1, 7);
    n1 = append(n1, 1);
    n1 = append(n1, 6);
    n2 = append(n2, 5);
    n2 = append(n2, 9);
    // n2 = append(n2, 2);

    print_list(n1);
    print_list(n2);
    s = sum_list_v2(n1, n2);
    print_list(s);

    return 0;
}

// First solution came to mind. It checks first the length of both numbers before processing
// the result, so it's a little bit less efficent than the recursive approach
list_int_t * sum_list(list_int_t * n1, list_int_t * n2) {
    list_int_t * x, * y;
    list_int_t * res = NULL;
    int n1_len, n2_len, i, offset, rem, sum;

    // Check the longest one, and set it as 'n1'
    n1_len = list_len(n1);
    n2_len = list_len(n2);
    if(n2_len > n1_len) {
        x = n1;
        n1 = n2;
        n2 = x;
        i = n1_len;
        n1_len = n2_len;
        n2_len = i;
    }

    offset = n1_len - n2_len;

    rem = 0;
    for(i=0; i<n1_len; i++) {
        if(i >= n2_len) {
            sum = n1->v + 0 + rem;
            n1 = n1->next;
        } else {
            sum = n1->v + n2->v + rem;
            n1 = n1->next;
            n2 = n2->next;
        }
        rem = sum / 10;
        res = append(res, sum % 10);
    }

    return res;
}

// Recursive solution to the problem
list_int_t * sum_list_v2(list_int_t * n1, list_int_t * n2) {
    list_int_t * res = NULL;
    int rem = 0;
    res = add_list(n1, n2, rem);
}

list_int_t * add_list(list_int_t * n1, list_int_t * n2, int rem) {
    int sum, new_rem, res;
    list_int_t * dig;

    if(n1 == NULL && n2 == NULL && rem==0)
        return NULL;
    else {
        printf(".\n");
        sum = rem;
        if (n1 != NULL)
            sum += n1->v;
        if (n2 != NULL)
            sum += n2->v;
        
        new_rem = sum / 10;
        res = sum % 10;

        dig = malloc(sizeof(list_int_t));
        dig->v = res;
        if(n1 != NULL || n2 != NULL)
            dig->next = add_list(
                n1 == NULL ? NULL : n1->next, 
                n2 == NULL ? NULL : n2->next,
                new_rem
            );
        else
            dig->next = NULL;
        
        return dig;
    }
}