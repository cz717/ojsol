#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
	int i, j, k;
    int l, r;
    int s, target;
    int cnt = 0;

    int **a = (int **) calloc(2048,  sizeof(int*));
    qsort(nums, numsSize, sizeof(nums[0]), cmp);

    for (i = 0; i < numsSize; i++) {
        if (i != 0 && nums[i] == nums[i-1])
            continue;

        target = 0 - nums[i];
        l = i + 1; 
        r = numsSize - 1;
        while (l < r) {
            s = nums[l] + nums[r];
            if (s == target) {
                // if (cnt == 0 || a[cnt-1][0] != nums[i] || a[cnt-1][1] != nums[l])
                a[cnt] = (int*) calloc(3, sizeof(int));
                a[cnt][0] = nums[i];
                a[cnt][1] = nums[l];
                a[cnt][2] = nums[r];
                
                while(l<numsSize && nums[l] == a[cnt][1]) l++;
                while(r>=0 && nums[r] == a[cnt][2]) r--;
                cnt++;
            } else if (s < target)
                l++;
            else
                r--;
        }
    }
    *returnSize = cnt;
    return a;
}


int main(void) {
    int a[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    int i, j, rs;

    int **p = threeSum(a, 15, &rs);
    for (i = 0; i < rs; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }

	return 0;
}
