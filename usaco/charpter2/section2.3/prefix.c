/*
ID: huajian2
LANG: C
TASK: prefix
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char primitive[201][11];
char s[2000001];
int max_prefix[2000001];
int pri_num, len;

/* 
  if pri is a prefix of s[start], return the len of pri;
  otherwise return 0
*/
int is_prefix(char *pri, int start)
{
	int l = 0;
	while (1) {
		if (pri[l] == '\0')
			return l;
		if (s[start++] != pri[l++]) /* include s[start] == '\n' */
			return 0;
	}
}

main () {
    FILE *fin  = fopen ("prefix.in", "r");
    FILE *fout = fopen ("prefix.out", "w");
    int ch;
    int start, i, j, l, max, this;

    pri_num = 0;
    while (1) {
    	fscanf (fin, "%s", primitive[pri_num]);
        if (primitive[pri_num][0] == '.')
            break;
        else
            pri_num++;
    }

    len = 0;
    while ((ch = fgetc(fin)) != EOF) {
    	if (isupper((char) ch))
    		s[len++] = (char) ch;
    }
    s[len] = '\0';

    max_prefix[len] = 0;
    for (start = len-1; start >= 0; start--) {
    	max = 0;
    	for (j = 0; j < pri_num; j++) {
    		l = is_prefix(primitive[j], start);
    		if (l) {
    			this = l + max_prefix[start + l];
    			if (this > max)
    				max = this;
    		}
    	}
    	max_prefix[start] = max;
    }

    fprintf (fout, "%d\n", max_prefix[0]);
    exit (0);
}
