#include <iostream>
#include <vector>
using namespace std;

// q[n][k] = amount of different staircases  built from exactly n bricks
//           while each step contains at least k bricks
long long q[501][502];

int main()
{
	int n;
	cin >> n;

	// q[n][k] = 1  if n = 0 or n = k
	for (int k = 0; k <= n + 1; ++k)
		q[0][k] = 1;
	// q[n][k] = 0  if n < k
	for (int i = 1; i <= n; ++i)
		for (int k = i + 1; k <= n + 1; ++k)
			q[i][k] = 0;

	// q[j][i]
	for (int i = n; i > 0; --i)
	{
		for (int j = i; j <= n; ++j)
		{
			long long sum = 0;
			for (int d = i; d <= j; ++d)
				sum += q[j - d][d + 1];
			q[j][i] = sum;
		}
	}

	cout << q[n][1] - 1 << endl;

	return 0;
}
