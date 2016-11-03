// ID   : 1501
// Title: Sense of Beauty
// Tags : dynamic programming

#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1005;
int dif[2][MAXN];
bool p[MAXN][MAXN];
int s[MAXN * 2];

int main()
{
	int n;
	cin >> n;
	
	string s1, s2;
	cin >> s1;
	cin >> s2;

	dif[0][0] = dif[1][0] = 0;
	for (int i = 0; i < n; ++i) {
		dif[0][i + 1] = dif[0][i] + ((s1[i] - '0') ? 1 : -1);
		dif[1][i + 1] = dif[1][i] + ((s2[i] - '0') ? 1 : -1);
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			int d = dif[0][i] + dif[1][j];
			p[i][j] = (abs(d) <= 1);
			if (i > 0 || j > 0) {
				bool x = (i > 0) ? p[i - 1][j] : false;
				bool y = (j > 0) ? p[i][j - 1] : false;
				p[i][j] = p[i][j] && (x || y);
			}
		}
	}

	if (p[n][n]) {
		int x = n, y = n;
		while (x > 0 || y > 0) {
			if (x > 0 && p[x - 1][y]) {
				s[x + y] = 1;
				--x;
			}
			else {
				s[x + y] = 2;
				--y;
			}
		}
		for (int i = 1; i <= 2 * n; ++i)
			cout << s[i];
		cout << endl;
	}
	else
		cout << "Impossible" << endl;

	return 0;
}