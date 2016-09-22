// ID   : 1210
// Title: Kind Spirits
// Tags : Graph Theory

#include <iostream>
using namespace std;

const int MAXN = 31;
const int INFINIT = 32767 * 30;
int fee[MAXN][MAXN];

int main()
{
	int n;
	int pre, cost;
	char c;

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> fee[i][0];
		for (int j = 1; j <= fee[i][0]; ++j)
		{
			fee[i][j] = INFINIT;
			while (cin >> pre && pre != 0)
			{
				cin >> cost;
				if (fee[i][j] > fee[i - 1][pre] + cost)
					fee[i][j] = fee[i - 1][pre] + cost;
			}
		}
		if (i != n)
			while (cin >> c && c != '*')
				/**/;
	}

	int min_fee = INFINIT;
	for (int i = 1; i <= fee[n][0]; ++i)
		if (min_fee > fee[n][i])
			min_fee = fee[n][i];
	cout << min_fee << endl;

	return 0;
}
