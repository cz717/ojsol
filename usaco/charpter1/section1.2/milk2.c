/*
ID: huajian2
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct time_section
{
	long begin;
	long end;
	struct time_section *next;
}TS;

main () {

    FILE *fin  = fopen ("milk2.in", "r");
    FILE *fout = fopen ("milk2.out", "w");
    int n;
    long begin, end;
    long max_continues = 0, max_idle = 0;
    long this_continues, this_idle;
    TS *tss, *p;

    tss = (TS*) malloc(sizeof(TS));
    tss->begin = 1000000;
    tss->end = 1000000;
    tss->next = NULL;

    fscanf (fin, "%d\n", &n);
    while (n--) {
    	fscanf(fin, "%ld %ld\n", &begin, &end);

    	for (p = tss; p != NULL; p = p->next) {
    		/* no overlap */
    		if (begin > p->end)
    			continue;

    		if (end < p->begin) {	/* insert infront */
    			TS *newss = (TS*) malloc(sizeof(TS));
    			newss->begin = p->begin;
    			newss->end = p->end;
    			newss->next = p->next;

    			p->begin = begin;
    			p->end = end;
    			p->next = newss;
    			break;
    		}

    		/* overlap */
    		if (begin < p->begin)
    			p->begin = begin;

    		if (end < p->end)		/* only overlap with this */	
    			break;
    		else {					/* overlap with multi section */
    			TS *nxt = p->next;
    			TS *temp;
    			while (nxt != NULL) {
    				if (end > nxt->end) {
    					temp = nxt;
    					nxt = nxt->next;
    					free(temp);
    					continue;
    				} else {
    					if (end < nxt->begin) {
    						p->end = end;
    						p->next = nxt;
    						break;
    					} else {
    						p->end = nxt->end;
    						p->next = nxt->next;
    						free(nxt);
    						break;
    					}
    				}
    			}
    			if (nxt == NULL)
    				p->end = end;
    			break;
    		} /* end of else */
    	}/* end of for */


    }

    long last_end = tss->begin;
    for (; tss != NULL && tss->begin < 1000000; tss = tss->next) {
    	this_continues = tss->end - tss->begin;
    	if (this_continues > max_continues)
    		max_continues = this_continues;

    	this_idle = tss->begin - last_end;
    	if (this_idle > max_idle)
    		max_idle = this_idle;

    	last_end = tss->end;
    }

    fprintf(fout, "%ld %ld\n", max_continues, max_idle);

    exit (0);
}
