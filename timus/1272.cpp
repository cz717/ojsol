// ID   : 1272
// Title: Non-Yekaterinburg Subway
// Tags : Graph Theory, Spanning Tree, Union-Find Set

#include <iostream>
using namespace std;

const int MAXN = 10005;
int ufset[MAXN];

int find(int x)
{
	if (ufset[x] != x)
		return ufset[x] = find(ufset[x]);
	else
		return x;
}

int main()
{
	int n, k, m;
	int a, b;
	int t = 0;

	for (int i = 0; i < MAXN; ++i)
		ufset[i] = i;

	cin >> n >> k >> m;
	for (int i = 0; i < k; ++i)
	{
		cin >> a >> b;
		int x = find(a);
		int y = find(b);
		if (x != y) {
			ufset[x] = y;
			++t;
		}
	}
	cout << (n - 1) - t << endl;

	return 0;
}
