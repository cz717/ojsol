#include <iostream>
#include <vector>
using namespace std;

int main()
{
	const int MAXN = 250 * 250;

	int N, K;
	cin >> N >> K;
	vector<int> horses(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> horses[i];

	// coefficient
	int coeff[501][501];
	int black, white;
	for (int begin = 1; begin <= N; ++begin)
	{
		black = white = 0;
		for (int end = begin; end <= N; ++end)
		{
			if (horses[end])
				++black;
			else
				++white;
			coeff[begin][end] = black * white;
		}
	}

	// c[n](k) is the minimum coefficient to put first n horses in first k stables
	vector<int> c(N + 1, MAXN);
	c[0] = 0;

	for (int i = 1; i <= K; ++i)	// first i stables
	{
		for (int j = N - K + i; j >= i; --j)	// first j horses
		{
			// C[j](i) = min{ C[j-k](i-1) + coeff[j-x+1][j] }
			int min = MAXN, cur;
			for (int k = 1; j - k >= i - 1; ++k)
			{
				cur = c[j - k] + coeff[j - k + 1][j];
				min = min > cur ? cur : min;
			}
			c[j] = min;
		}
	}

	cout << c[N] << endl;

	return 0;
}
