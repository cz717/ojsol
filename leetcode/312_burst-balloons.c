int maxCoins(int* nums, int size) {
	int s = size + 2;
	int* n = (int *)malloc(sizeof(int)* s);
	n[0] = n[s - 1] = 1;
	for (int i = 0; i < size; ++i)
		n[i + 1] = nums[i];

	long long **c = (long long **)malloc(sizeof(long long*) * s);
	for (int i = 0; i < s; ++i)
		c[i] = (long long *)malloc(sizeof(long long) * s);
	for (int i = 0; i < s; ++i)
		c[i][i] = 0;

	for (int d = 1; d < s - 1; ++d)
	{
		for (int i = 1; i < s - d; ++i)
		{
			int j = i + d;
			int max = 0, sum = 0;
			for (int k = i; k < j; ++k)
			{
				sum = c[i][k] + c[k + 1][j] + n[i - 1] * n[k] * n[j];
				max = (max > sum) ? max : sum;
			}
			c[i][j] = max;
		}
	}

	return c[1][s - 1];
}