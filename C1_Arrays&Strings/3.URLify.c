#include <stdio.h>
#include <string.h>
#define MAXLEN 200

void urlify(char *, int);

int main(void) {
    char str[MAXLEN+1] = "I HATE spaces";
    int len = strlen(str);

    urlify(str, len);
    printf("%s", str);

    return 0;
}

void urlify(char * str, int len) {
    int rlen, i, p;

    rlen = len;
    for(i=0; i<len; i++)
        if(str[i] == ' ') {
            rlen += 2;            
            printf("%d\n", i);
        }
    printf("RES %d %d\n", rlen, len);

    p = rlen-1;
    for(i=len-1; i>=0; i--) {
        if(str[i] == ' ') {
            str[p] = '0'; str[p-1] = '2'; str[p-2] = '%';
            p -= 3;
        } else {
            str[p] = str[i];
            p--; 
        }
    }
}
