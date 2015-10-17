/*
ID: huajian2
LANG: C
TASK: harmming
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *fin;
FILE *fout;
int n, b, d;
unsigned char code[65];

int harm_dis(unsigned char a, unsigned char b)
{
    int i, dis = 0;
    unsigned char c = a ^ b;
    for (i = 0; i < 8; i++) {
        dis += c % 2;
        c /= 2;
    }
    return dis;
}

bool find(int deep, unsigned char last)
{
//    printf("fin(%d, %d)\n", deep, last); ///////////////
    unsigned char this;
    unsigned int ui;
    int i, j;
    bool ok;

    if (deep == 1)
        ui = 0;
    else
        ui = last + 1;

    for (; ui < 256; ui++) {
        this = (unsigned char) ui;
        ok = true;
        for (i = 1; i < deep; i++)
            if (harm_dis(code[i], this) < d) {
                ok = false;
                break;
            }

        if (ok) {
            code[deep] = this;
            if (deep == n) {        /* all n code found */
                for (j = 1; j <= n; j++) {
                    fprintf(fout, "%d", code[j]);
                    if (j%10 == 0 || j == n)
                        fprintf(fout, "\n");
                    else
                        fprintf(fout, " ");
                }
                return true;
            } else {
                if(find(deep+1, this))
                    return true;
            }
        }
    }
    return false;
}

main () {
    fin  = fopen ("harmming.in", "r");
    fout = fopen ("harmming.out", "w");

    fscanf (fin, "%d %d %d", &n, &b, &d);
    find(1, 0);

    exit (0);
}
