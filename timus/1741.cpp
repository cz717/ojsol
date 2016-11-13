// ID   : 1741
// Title: Communication Fiend
// Tags : dynamic programming

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct prog {
	int x, y, d, s;
	prog(int a = 1, int b = 1, int m = 0, string t = "")
		: x(a), y(b), d(m), s(0) {
		if (t == "Licensed")
			s = 0;
		else if (t == "Cracked")
			s = 1;
		else if (t == "Pirated")
			s = 2;
	};
};

const int MAXN = 10005;
const long long INF = 10000000005;
long long c[2][MAXN];
int n, m;

int main()
{
	int x, y, d;
	string s;
	vector<prog> v;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> d;
		cin >> s;
		v.push_back(prog(x, y, d, s));
	}
	sort(v.begin(), v.end(), [](prog &a, prog &b) {return a.y < b.y;});

	c[0][1] = 0;
	c[1][1] = INF;
	int p = 0;
	for (int i = 2; i <= n; ++i) {
		c[0][i] = c[1][i] = INF;
		for (; p < m && v[p].y <= i; ++p) {
			if (v[p].s <= 1)
				c[0][i] = min(c[0][i], c[0][v[p].x] + v[p].d);
			if (v[p].s >= 1)
				c[1][i] = min(c[1][i], c[1][v[p].x] + v[p].d);
			if (v[p].s == 2)
				c[1][i] = min(c[1][i], c[0][v[p].x] + v[p].d);
		}
	}

	long long mind = min(c[0][n], c[1][n]);
	if (mind < INF)
		cout << "Online\n" << mind << endl;
	else
		cout << "Offline" << endl;

	return 0;
}