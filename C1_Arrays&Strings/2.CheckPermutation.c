#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALPH_COUNT 128


int check_permutation(char *, char *);
int check_permutation_v2(char *, char *);
int cmp_arrays(int *, int *, int);

int main(void) {
    char str1[] = "abcdefghi";
    char str2[] = "ihgfedcba";

    printf("%d\n", check_permutation(str1, str2));
    printf("%d\n", check_permutation_v2(str1, str2));

    return 0;
}

int check_permutation(char * a, char * b) {
    int count_a[ALPH_COUNT] = {0};
    int count_b[ALPH_COUNT] = {0};
    int i;

    i=0;
    while(a[i]!='\0' && b[i]!='\0') {
        count_a[a[i]]++;
        count_b[b[i]]++;
        i++;
    }

    if(a[i] == b[i]) 
        return cmp_arrays(count_a, count_b, ALPH_COUNT);
    else
        return 0;
}

int check_permutation_v2(char * a, char * b) {
    int count[ALPH_COUNT] = {0};
    int i;

    i=0;
    while(a[i]!='\0' && b[i]!='\0') {
        count[a[i]]++;
        count[b[i]]--;
        i++;
    }

    if(a[i] == b[i]) {
        for(i=0; i<ALPH_COUNT && count[i]==0; i++);
        return i==ALPH_COUNT;
    } else
        return 0;
}

int cmp_arrays(int * a, int * b, int len) {
    int i;
    for(i=0; i<len && a[i]==b[i]; i++);
    return i==len;
}