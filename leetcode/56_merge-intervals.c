#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int cmpx(const void *a, const void *b) {
	struct Interval *x = (struct Interval *) a;
	struct Interval *y = (struct Interval *) b;
	return x->start - y->start;
}

void itv_copy(struct Interval *from, struct Interval *to) {
	to->start = from->start;
	to->end = from->end;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    int cnt, i;
    struct Interval *res = (struct Interval *) calloc(intervalsSize, sizeof(intervals));

    qsort(intervals, intervalsSize, sizeof(struct Interval), cmpx);
    itv_copy(intervals, res);

    for (cnt = -1, i = 0; i < intervalsSize; i++) {
    	if (cnt == -1 || intervals[i].start > res[cnt].end) {
    		++cnt;
    		itv_copy(intervals+i, res+cnt);
    	}
    	else if (intervals[i].end > res[cnt].end) {
    		res[cnt].end = intervals[i].end;
    	}
    }

    *returnSize = cnt + 1;
    return res;
}


