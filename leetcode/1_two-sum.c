#include <stdio.h>
#include <stdlib.h>

int cmp(void *a, void *b) {
	return *((int *) a) - *((int *) b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *onum = (int *) malloc(sizeof(int) * numsSize);
    int *idx = (int *) malloc(sizeof(int) * 2);
    int i, j, k, p;

    for (i = 0; i < numsSize; i++)
    	onum[i] = nums[i];
    qsort (onum, numsSize, sizeof(onum[0]), cmp);

    for (i = 0, j = numsSize-1; i < j; i++)
    	while (onum[i] + onum[j] >= target) {
    		if (onum[i] + onum[j] == target) {
    			for (k = 0, p = 0; k < numsSize; k++) {
                    if (nums[k] == onum[i] || nums[k] == onum[j])
                        idx[p++] = k + 1;
                }
                free(onum);
    			qsort (idx, 2, sizeof(idx[0]), cmp);
    			return idx;
    		} else
    			--j;
    	}

    free(onum);
    free(idx);
    return NULL;
}


int main(void) {
	int nums[] = {0, 4, 3, 0};
	int *idx = twoSum(nums, 4, 0);
	printf("%d %d\n", idx[0], idx[1]);
	free(idx);
	return 0;
}
