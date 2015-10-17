#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}


int threeSumClosest(int* nums, int numsSize, int target) {
    int i, l, r, s;
    int csum = nums[0] + nums[1] + nums[2];
    int closest = abs(csum - target);

    qsort(nums, numsSize, sizeof(int), cmp);

    for (i = 0; i < numsSize; i++) {
    	l = i + 1;
    	r = numsSize - 1;
    	while (l < r) {
    		s = nums[i] + nums[l] + nums[r];
    		if (closest > abs(s-target)) {
    			closest = abs(s-target);
    			csum = s;
    		}
    		if (s > target)
    			r--;
    		else
    			l++;
    	}
    }

    return csum;
}


int main(void) {
	int a[] = {-1, 2, 1, -4};
	printf("%d\n", threeSumClosest(a, 4, 1));

	return 0;
}