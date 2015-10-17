#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_next(char *p, int *next, int lenp) {
	int i = 0, n = -1;
	next[0] = -1;
	while (i < lenp) {
		if (n == -1 || p[i] == p[n]) {
			++i;
			++n;
			next[i] = n;
		} else
			n = next[n];
	}
}

int strStr(char* haystack, char* needle) {
    int lent = strlen(haystack);
    int lenp = strlen(needle);
    int *next = (int*) calloc(lenp, sizeof(int));
    int post, posp;

    get_next(needle, next, lenp);

    post = posp = 0;
    while (post < lent && posp < lenp) {
    	if (posp == -1 || haystack[post] == needle[posp]) {
    		++posp;
    		++post;
    	} else
    		posp = next[posp];
    }

    free(next);
    if (posp < lenp)
    	return -1;
    else
    	return post - lenp;
}

int main(void) {
	printf("%d\n", strStr("mississippi", "issipi"));
	return 0;
}