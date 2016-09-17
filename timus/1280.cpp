#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<set<int>> next(n + 1, set<int>());	// graph
	vector<set<int>> pre(n + 1, set<int>());	// reverse graph
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		next[a].insert(b);
		pre[b].insert(a);
	}

	int cur;
	for (int i = 0; i < n; ++i)
	{
		cin >> cur;
		if (pre[cur].empty())
		{
			for (auto n : next[cur])
				pre[n].erase(cur);
		}
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;
}