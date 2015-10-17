#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* longestPalindrome(char* s) {
    int len = strlen(s);
    int left, mid, right, i;
    int max = 0, start = 0;

    for (i = 0; i <= 2*len - 2 - max; i++) {
    	if (i%2) {
    		left = (i-1)/2;
    		right = (i+1)/2;
    	} else
    		left = right = i/2;

    	while (left >= 0 || right < len) {
    		if (s[left] != s[right])
    			break;
    		else {
    			--left;
    			++right;
    		}
    	}
    	if (max < right-left-1) {
    		max = right-left-1;
    		start = left+1;
    	}
    }

    char *pal = (char *) malloc(sizeof(char) * (max+1));
    strncpy(pal, s+start, max);
    pal[max] = '\0';
    // printf("%d %s", max, pal); 
    return pal;
}


int main(void) {
	char *s = "\0";
	printf("%s\n", longestPalindrome(s));
	return 0;
}
