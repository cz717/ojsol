// ID   : 1080
// Title: Map Coloring
// Tags : Graph Theory, Deep First Search

#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAXN = 100;
list<int> g[MAXN];
int color[MAXN];

bool coloring(int i, int c)
{
	int n = c ? 0 : 1;
	if (color[i] == c)
		return true;
	else if (color[i] == n)
		return false;
	else
	{
		color[i] = c;
		for (auto x : g[i])
			if (!coloring(x, n))
				return false;
		return true;
	}

}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int j;
		while (cin >> j && j != 0)
		{
			g[i].push_back(j);
			g[j].push_back(i);
		}
	}

	for (int i = 0; i < MAXN; ++i)
		color[i] = -1;

	bool suc = true;
	for (int i = 1; i <= N; ++i)
		if (color[i] == -1)
			if (!coloring(i, 0))
			{
				suc = false;
				break;
			}

	if (suc)
	{
		for (int i = 1; i <= N; ++i)
			cout << color[i];
		cout << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}