#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lengthOfLongestSubstring(char* s) {
	int alphabet[256];
    int left, right;
    int max, len, i;
    char c;

    for (i = 0; i < 256; i++)
    	alphabet[i] = 0;
    left = right = max = 0;

    len = strlen(s);
    for (right = 0; right < len; right++) {
    	c = s[right];
    	if (!alphabet[c]) {
    		alphabet[c] = 1;
    		continue;
    	} else {

    		if (max < right - left)
    			max = right - left;

    		for (i = left; i < right; i++) {
    			if (s[i] == s[right]) {
    				left = i + 1;
    				break;
    			} else
    				alphabet[s[i]] = 0;
    		}
    	}
    }
    if (max < right - left)
    	max = right - left;

    return max;
}

int main(void) {
	char *s = "afdlaljfdkall#$%*&()*)*_dfadalfd";
	printf("%d\n", lengthOfLongestSubstring(s));
	return 0;
}
