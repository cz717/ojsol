#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

#define max(x, y)  ((x) > (y))? (x) : (y)
#define min(x, y)  ((x) > (y))? (y) : (x)

void itv_copy(struct Interval *from, struct Interval *to) {
	to->start = from->start;
	to->end = from->end;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    struct Interval* res = (struct Interval*) calloc(intervalsSize + 1, sizeof(struct Interval));
    int p = 0, q = 0;

    while(p < intervalsSize && intervals[p].end < newInterval.start) {
    	itv_copy(intervals + p, res + q);
    	++p; ++q;
    }

    if (p == intervalsSize || intervals[p].start > newInterval.end) {
    	itv_copy(&newInterval, res + q);
    	++q;
    } else {
    	res[q].start = min(newInterval.start, intervals[p].start);
    	while (p < intervalsSize && intervals[p].start <= newInterval.end)	++p;
    	--p;
    	res[q].end = max(newInterval.end, intervals[p].end);
    	++p; ++q;
    }

    while (p < intervalsSize) {
    	itv_copy(intervals + p, res + q);
    	++p; ++q;
    }

    *returnSize = q + 1;
    return res;
}