#include <stdio.h>
#include <stdlib.h>

char* intToRoman(int num) {
	char *roman = (char *) malloc(sizeof(char) * 17);
    char r[4][2] = {{'I', 'V'}, 
    				{'X', 'L'},
    				{'C', 'D'},
    				{'M', ' '}};
    int n[4];
    int i, j, p = 0;

    for (i = 0; i < 4; i++) {
    	n[i] = num % 10;
    	num /= 10;
    }

    for (i = 3; i >= 0; i--) {
    	if (n[i] == 0)	continue;
    	if (n[i] <= 3)
    		while (n[i]--)
    			roman[p++] = r[i][0];
    	if (n[i] == 4) {
    		roman[p++] = r[i][0];
    		roman[p++] = r[i][1];
    	}
    	if (n[i] >= 5 && n[i] <= 8) {
    		roman[p++] = r[i][1];
    		while (n[i]-- > 5) roman[p++] = r[i][0];
    	}
    	if (n[i] == 9) {
    		roman[p++] = r[i][0];
    		roman[p++] = r[i+1][0];
    	}
    }
    roman[p] = '\0';
    return roman;
}



int main(void) {
	printf("%s\n", intToRoman(3999));

	return 0;
}