// ID   : 1362
// Title: Classmates 2
// Tags : dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100002;
int f[MAXN];		// father
vector<int> g[MAXN];	// children
int c[MAXN];		// time
int n, tanya;

class cmp {
public:
	bool operator()(int lhs, int rhs) {
		return c[lhs] > c[rhs];
	}
} comp;

int dp(int r) {
	if (c[r] == -1) {
		if (g[r].empty())
			c[r] = 0;
		else {
			for (auto x : g[r])
				dp(x);
			sort(g[r].begin(), g[r].end(), comp);
			int m = 0;
			for (int i = 0; i < g[r].size(); ++i)
				if (m < c[g[r][i]] + i + 1)
					m = c[g[r][i]] + i + 1;
			c[r] = m;
		}
	}
	return c[r];
}

int main()
{
	cin >> n;
	int x;
	for (int i = 1; i <= n; ++i) {
		while (cin >> x && x != 0) {
			g[i].push_back(x);
			f[x] = i;
		}
	}
	cin >> tanya;

	// set Tanya as root
	int a = 0, b = tanya, t;
	while (b != 0) {
		if (a) {
			g[a].push_back(b);
			g[b].erase(find(g[b].begin(), g[b].end(), a));
		}
		t = f[b];
		f[b] = a;
		a = b;
		b = t;
	}


	for (int i = 0; i < MAXN; ++i)
		c[i] = -1;
	cout << dp(tanya) << endl;

	return 0;
}