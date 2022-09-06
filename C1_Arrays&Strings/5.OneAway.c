#include <stdio.h>

int one_way(char *, char *);

int main(void) {
    char s1[] = "pales";
    char s2[] = "pale";

    printf("%d", one_way(s1, s2));

    return 0;
}

// Should be a little bit more efficent than the solution in the book
// Strings are compared letter by letter simultaneously without identifying
// the shorter one and the longer one. 
int one_way(char * s1, char * s2) {
    int i, j, changes;

    i=0; j=0; changes=0;
    while((s1[i]!='\0' || s2[j]!='\0') && changes<2) {
        if(s1[i] != s2[j]) {
            changes++;
            if(s1[i+1] == s2[j])
                i++;
            else if(s1[i] == s2[j+1])
                j++;
            else
                changes++;
        }
        if(s1[i]!='\0') i++;
        if(s2[j]!='\0') j++;
    }

    printf("C: %d\n", changes);
    return changes<2;
}