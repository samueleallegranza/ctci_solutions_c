#include <stdio.h>
#include "../lib/uthash/src/uthash.h"

struct my_struct {
    int id;            /* we'll use this field as the key */
    char name[10];
    UT_hash_handle hh; /* makes this structure hashable */
};

struct my_struct *users = NULL;



void add_user(int user_id, char *name) {
    struct my_struct *s;

    HASH_FIND_INT(users, &user_id, s);  /* id already in the hash? */
    if (s == NULL) {
      s = (struct my_struct *)malloc(sizeof *s);
      s->id = user_id;
      HASH_ADD_INT(users, id, s);  /* id: name of key field */
    }
    strcpy(s->name, name);
}



struct my_struct *find_user(int user_id) {
    struct my_struct *s;

    HASH_FIND_INT( users, &user_id, s );
    return s;
}

void delete_user(struct my_struct *user) {
    HASH_DEL( users, user);
}

