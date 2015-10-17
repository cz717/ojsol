/*
ID: huajian2
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main () {

    struct friend
    {
    	char name[15];
    	int band;
    };

    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    int NP, i, j, k;
    struct friend friends[10];
    char giver[15], recipient[15];
    int gift, people, money;

    fscanf (fin, "%d\n", &NP);		/* read NP */
    for (i = 0; i < NP; i++) {
    	fscanf(fin, "%s", friends[i].name);
    	friends[i].band = 0;
    }

    for (i = 0; i < NP; i++) {
    	fscanf(fin, "%s", giver);	/* read giver */
    	fscanf(fin, "%d %d", &gift, &people);
    	if (people != 0)
    		money = gift / people;

    	for (j = 0; j < NP; j++) {
    		if ( !strcmp(friends[j].name, giver)) {
    			friends[j].band -= money * people;
    			break;
    		}
    	}

    	for (j = 0; j < people; j++) {
    		fscanf(fin, "%s", recipient);
    		for (k = 0; k < NP; k++)
    			if ( !strcmp(friends[k].name, recipient)) {
    				friends[k].band += money;
    				break;
    			}
    	}
    }

    for (i = 0; i < NP; i++)
    	fprintf (fout, "%s %d\n", friends[i].name, friends[i].band);

    exit (0);
}