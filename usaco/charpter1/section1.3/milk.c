/*
ID: huajian2
LANG: C
TASK: milk
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct farmer
{
	int price;
	long amount;
} FARMER;

int fmr_cmp(const void *a, const void *b)
{
	FARMER *af = ((FARMER *)a);
	FARMER *bf = ((FARMER *)b);
	return af->price > bf->price;
}

main () {
    FILE *fin  = fopen ("milk.in", "r");
    FILE *fout = fopen ("milk.out", "w");
    long N, money;
    int M, i;
    FARMER *farmers;

    fscanf (fin, "%ld %d\n", &N, &M);
    farmers = (FARMER *) malloc(sizeof(FARMER) * M);
    for (i = 0; i < M; i++)
    	fscanf(fin, "%d %ld\n", &farmers[i].price, &farmers[i].amount);

    qsort(farmers, M, sizeof(farmers[0]), fmr_cmp);

    money = 0;
    for (i = 0; i < M && N > 0; i++) {
        if (N >= farmers[i].amount) {
            N -= farmers[i].amount;
            money += farmers[i].price * farmers[i].amount;
        } else {
            money += farmers[i].price * N;
            N = 0;
        }
    }

    fprintf(fout, "%ld\n", money);
    exit (0);
}
