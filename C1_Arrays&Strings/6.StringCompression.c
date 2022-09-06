#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CH_ZERO '0'

char * str_compression(char *);

int main(void) {
    char str[] = "aabbbcccccd";
    char *cmp;

    cmp = str_compression(str);
    printf("%s\n", cmp);

    return 0;
}

char * str_compression(char * str) {
    char * cmp;
    int curr, adder;
    int len, cmp_len, chg_num;
    int i, j;

    // evaluate changes
    chg_num=1; len=1;
    curr = str[0];
    while(str[len] != '\0'){
        if(curr != str[len]) {
            curr = str[len];
            chg_num++;
        }
        len++;
    }

    cmp_len = chg_num*2;
    cmp = malloc(sizeof(char) * (cmp_len+1)); // +1 for 'string terminator'

    if(cmp_len < len) {        
        adder = 1;
        curr = str[0];
        i=1; j=0;
        while(str[i] != '\0') {
            if(str[i] == curr) {
                adder++;
            } else {
                *(cmp+j) = curr;
                *(cmp+j+1) = adder + CH_ZERO;
                j += 2;
                curr = str[i];
                adder = 1;
            }
            i++;
        }
        cmp[j] = curr;
        cmp[j+1] = adder + CH_ZERO;
        // Add string terminator to secure end of string.
        cmp[j+2] = '\0';
    } else {
        memcpy(cmp, str, sizeof(char)*(len+1));
    }

    return cmp;
}

// abcd -> a1b1 c1d1        c = 4   l = 4   (2*c)<l F
// aabb -> a2b2             c = 2   l = 4   (2*c)<l F
// abb ->  a1b2             c = 2   l = 3   (2*c)<l F
// aaa ->  a3               c = 1   l = 3   (2*c)<l V
