// ID   : 1081
// Title: Binary Lexicographic Sequence
// Tags : Dynamic Programming

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;

	// C(i, 0) = C(i - 1, 0) + C(i - 1, 1)
	// C(i, 1) = C(i - 1, 0)
	long long c[45];
	c[0] = c[1] = 1;
	for (int i = 2; i <= n + 1; ++i)
		c[i] = c[i - 1] + c[i - 2];

	if (k > c[n + 1])
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		int num[45];
		for (int i = n; i > 0; --i)
		{
			if (k > c[i])
			{
				num[i] = 1;
				k -= c[i];
			}
			else
				num[i] = 0;
		}
		for (int i = n; i > 0; --i)
			cout << num[i];
		cout << endl;
	}

	return 0;
}
