// ID   : 1267
// Title: Mars Canals
// Tags : dynamic programming

#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1405;
string square[2];
int cnt[2][MAXN][4];

int dx[4] = { 0, -1, -1, -1 };
int dy[4] = { -1, -1, 0, 1 };

int main()
{
	int n;
	cin >> n;

	int maxs = 0, maxS = 0;
	int last, cur;
	for (int i = 0; i < n; ++i) {
		cur = i % 2;
		last = (i + 1) % 2;
		cin >> square[cur];
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 4; ++k)
				cnt[cur][j][k] = 1;

			for (int k = 0; k < 4; ++k) {
				if (i + dx[k] < 0 || j + dy[k] < 0 || j + dy[k] >= n)
					continue;
				int x = (cur + dx[k] + 2) % 2;
				int y = j + dy[k];
				if (square[x][y] == square[cur][j])
					cnt[cur][j][k] += cnt[x][y][k];
			}

			int m = 0;
			for (int k = 0; k < 4; ++k)
				if (m < cnt[cur][j][k])
					m = cnt[cur][j][k];
			if (square[cur][j] == 's' && maxs < m)
				maxs = m;
			else if (square[cur][j] == 'S' && maxS < m)
				maxS = m;
		}
	}

	if (maxs > maxS)
		cout << "s" << endl << maxs << endl;
	else if (maxs < maxS)
		cout << "S" << endl << maxS << endl;
	else
		cout << "?" << endl << maxs << endl;

	return 0;
}