/*
ID: huajian2
LANG: C
TASK: contact
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct pattern
{
    char p[13];
    int cnt;
}pattern;

int pat_to_idx(char * p);
int cmp(const void *x, const void *y);
void gen_pat(int deep);
void rd_pat(char *begin, int len);

char s[200005];
pattern ptn[10000];
char p[13];


main () {
    FILE *fin  = fopen ("contact.in", "r");
    FILE *fout = fopen ("contact.out", "w");

    int a, b, n;
    int l, begin, end, len, idx;
    int i, j;
    char c;

    l = 0;
    fscanf (fin, "%d %d %d", &a, &b, &n);
    while ((i = fgetc(fin)) != EOF) {
        c = (char) i;
    	if (c == '0' || c == '1')
    		s[l++] = c;
    }
    s[l] = '\0';

    gen_pat(0);

    for (len = a; len <= b; len++) {
        j = l - len;
        for (i = 0; i <= j; i++) {
            rd_pat(s+i, len);
            idx = pat_to_idx(p);
            ptn[idx].cnt++;
        }
    }

    begin = pow(2, a);
    end = pow(2, b+1) - 1;

    qsort(ptn+begin, end-begin+1, sizeof(ptn[0]), cmp);


    if (end > begin + l - 1)
        end = begin + l -1;
    int fre, lc;
    for (i = 0, j = begin; i < n && j <= end; i++) {
        fre = ptn[j].cnt;
        if (fre == 0) 
            break;
        fprintf(fout, "%d", fre);
        lc = 0;
        while (j <= end && ptn[j].cnt == fre) {
            if (lc == 0)
                fprintf(fout, "\n");
            else
                fprintf(fout, " ");
            fprintf(fout, "%s", ptn[j].p);
            lc = (lc + 1) % 6;
            ++j;
        }
        fprintf(fout, "\n");
    }

    exit(0);
}

int pat_to_idx(char * p)
{
    int l = strlen(p);
    int i, idx = 1;
    for (i = 0; i < l; i++) {
        if (p[i] == '0')
            idx *= 2;
        else
            idx = 2*idx + 1;
    }
    return idx;
}

int cmp(const void *x, const void *y)
{
    pattern *a = (pattern *) x;
    pattern *b = (pattern *) y;
    if (a->cnt != b->cnt)
        return b->cnt - a->cnt;
    else if (strlen(a->p) != strlen(b->p))
        return strlen(a->p) - strlen(b->p);
    else
        return strcmp(a->p, b->p);
}

void gen_pat(int deep)
{
    int idx;
    if (deep < 12) {
        p[deep] = '0';
        p[deep+1] = '\0';
        idx = pat_to_idx(p);
        strcpy(ptn[idx].p, p);
        ptn[idx].cnt = 0;
        gen_pat(deep+1);

        p[deep] = '1';
        p[deep+1] = '\0';
        idx = pat_to_idx(p);
        strcpy(ptn[idx].p, p);
        ptn[idx].cnt = 0;
        gen_pat(deep+1);
    } else
        return;
}

void rd_pat(char *begin, int len)
{
    int i;
    for (i = 0; i < len; i++)
        p[i] = begin[i];
    p[len] = '\0';
}
