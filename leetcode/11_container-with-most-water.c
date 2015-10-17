#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a<b? a : b)

int maxArea(int* height, int heightSize) {
    int l = 0, r = heightSize - 1;
    int lh = height[l], rh = height[r];
    int max = min(lh, rh) * (r - l);
    int area;
    
    while (l < r) {
        if (lh < rh) {
            while(height[++l] <= lh && l < r) ;
            lh = height[l];
        } else {
            while(height[--r] <= rh && r > l) ;
            rh = height[r];
        }

        area = min(lh, rh) * (r - l);
        if (max < area)
            max = area;
    }

    return max;
}

int main(void) {
	int h[15000];
	int i;
	for (i = 0; i < 15000; i++)
		h[i] = i + 1;
	
	printf("%d\n", maxArea(h, 15000));

	return 0;
}
