#ifndef LIST_INT_H
#define LIST_INT_H

typedef struct listi_s {
    int v;
    struct listi_s * next;
} list_int_t;

/* Insert ahead of list */
list_int_t * push(list_int_t * h, int val);

/* Insert at the end of list */
list_int_t * append(list_int_t * h, int val);

/* Remove element ahead of list */
list_int_t * pop(list_int_t * h, int val);

/* Delete every element of the list with the specified value */
list_int_t * delete_all(list_int_t * h, int val);

/* Delete the first element of the list with the specified value */
//listi_t * delete(listi_t * h, int val);

/* Search for a specified value in the list, returns the first position if present, otherwhise returns -1  */
int find_value(list_int_t * h, int value);

/* Clear the list */
void freelist(list_int_t * h);

/* Calculate length of list */
int list_len(list_int_t * h);

/* Print the elements of the list */
void print_list(list_int_t * h);

#endif
