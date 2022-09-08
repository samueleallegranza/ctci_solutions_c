#include <stdio.h>
#include <stdlib.h>

#include "list_int.h"

#define ERR_ALLOC "Memory allocation error\n"
#define ERR_EMPTY "List is empty\n"

list_int_t * push(list_int_t * h, int v) {
    list_int_t * new;

    new = malloc(sizeof(list_int_t));
    if(new) {
        new->v = v;
        new->next = h;
        h = new;
    } else {
        printf("%s", ERR_ALLOC);
    }

    return h;
}

list_int_t * append(list_int_t * h, int v) {
    list_int_t * new;
    list_int_t * p;

    new = malloc(sizeof(list_int_t));
    if(new) {
        new->v = v;
        new->next = NULL;
        if(h == NULL) {
            h = new;
        } else {
            p = h;
            while(p->next != NULL)
                p = p->next;
            p->next = new;
        }
    } else {
        printf("%s", ERR_ALLOC);
    }

    return h;
}

int find_value(list_int_t * h, int value) {
    list_int_t * p = h;
    int pos = 0;
    int found = 0;

    while(p != NULL && !found) {
        if(p->v == value)
            found = 1;
        else
            pos++;
        p = p->next;
    }

    if(found)
        return pos;
    else
        return -1; // not found
}

void freelist(list_int_t * h) {
    list_int_t * tmp;

   while (h != NULL) {
        tmp = h;
        h = h->next;
        free(tmp);
    }
}

int list_len(list_int_t * h) {
    int count;
    list_int_t * p;

    count = 0;
    p=h;
    while(p != NULL) {
        count++;
        p = p->next;
    }

    return count;
}

list_int_t * delete_all(list_int_t * h, int n) {
    list_int_t * p, *prev;

    p=h;
    while(p != NULL && p->v == n){
        h = p->next;
        free(p);
        p = h;
    }
    if(p != NULL) {
        prev = p;
        p = p->next;
        while(p!=NULL) {
            if(p->v == n) {
                prev->next = p->next;
                free(p);
                p = prev->next;
            } else {
                p = p->next;
                prev = prev->next;
            }
        }
    }

    return h;
}

void print_list(list_int_t * h) {
    list_int_t * p;

    if(h == NULL) {
        printf("Empty.\n");
    } else {
        p = h;
        while(p != NULL) {
            printf("[%d]->", p->v);
            p = p->next;
        }
        printf("\n");
    }
}