// ID   : 1148
// Title: Maximum Sum
// Tags : Dynamic Programming

#include <iostream>
using namespace std;

const int MAXN = 101;
const int NINF = -2000000;

int m[MAXN];
int s[MAXN][MAXN];

int max(int x, int y) {
	return (x > y) ? x : y;
}

int main()
{
	int n;
	cin >> n;

	int max_sum = NINF;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> m[j];
			m[j] += m[j - 1];
		}

		for (int l = 1; l <= n; ++l) {
			for (int r = l; r <= n; ++r) {
				int x = m[r] - m[l - 1];
				s[l][r] = max(s[l][r] + x, x);
				if (max_sum < s[l][r])
					max_sum = s[l][r];
			}
		}
	}
	cout << max_sum << endl;

	return 0;
}