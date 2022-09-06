#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#define LEN 10
#define ALPH_COUNT 128

int is_unique(char *);
int is_unique_bitvector(char *);

int main(void) {
    char str[LEN+1] = "abcdefghii";
    printf("%d\n", is_unique(str));
    printf("%d\n", is_unique_bitvector(str));
    return 0;
}

int is_unique(char * str) {
    bool counter[ALPH_COUNT] = {0};
    int i, norep;

    i=0; norep=1;
    while(str[i]!='\0' && norep) {
        if(counter[str[i]] == 0)
            counter[str[i]] = 1;
        else
            norep = 0;
        i++;
    }

    return norep;
}

int is_unique_bitvector(char * str) {
    uint32_t bitvect = 0, idx;
    int i, rep;

    i=0; rep=0;
    while(str[i]!='\0' && !rep) {
        idx = str[i] - 'a';
        rep = (bitvect & (1 << idx)) != 0;
        bitvect = bitvect | (1 << idx);
        i++;
    }

    return !rep;
}
