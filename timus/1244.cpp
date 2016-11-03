// ID   : 1244
// Title: Gentlemen
// Tags : dynamic programming, 0-1 knapsack

#include <iostream>
#include <map>
using namespace std;

const int MAXN = 105;
int n;
int w[MAXN];
bool v[MAXN];
map<int, int> m[MAXN];	

int dp(int s, int k) {
	if (m[k].find(s) == m[k].end()) {
		if (s == 0)
			m[k][s] = 1;
		else if (k == 0)
			m[k][s] = 0;
		else {
			m[k][s] = dp(s, k - 1);
			if (s >= w[k]) {
				int x = dp(s - w[k], k - 1);
				if (x)
					v[k] = true;
				m[k][s] += x;
			}
		}
	}
	return m[k][s];
}

int main()
{
	int incomp, comp = 0;
	cin >> incomp >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		comp += w[i];
	}

	int miss = comp - incomp;
	int cnt = dp(miss, n);

	if (cnt == 0)
		cout << 0 << endl;
	else if (cnt > 1)
		cout << -1 << endl;
	else {
		for (int i = 1; i <= n; ++i)
			if (v[i])
				cout << i << " ";
		cout << endl;
	}

	return 0;
}