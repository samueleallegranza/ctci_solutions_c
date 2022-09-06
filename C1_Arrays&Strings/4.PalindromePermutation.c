#include <stdio.h>
#define ALPH_COUNT 'z'-'a'

int pal_perm(char *);

int main(void) {
    char str[] = "tact coa";
    printf("%d\n", pal_perm(str));
    return 0;
}

// supposing that string is lower-case
int pal_perm(char * str) {
    int count[ALPH_COUNT] = {0};
    int i, odd;

    // count letters
    i = 0;
    while(str[i] != '\0'){
        if(str[i] != ' ')
            count[str[i] - 'a']++;
        i++;
    }

    // check if odd counters are less or equal than 1
    odd = 0;
    for(i=0; i<ALPH_COUNT && odd <=1; i++){
        if(count[i] != 0 && count[i]%2 != 0)
            odd++;
    }

    // check if even/odd combination corresponds to palindrome permutations
    // & return the evaluation
    return (odd <= 1);
}

