// ID   : 1022
// Title: Genealogical Tree
// Tags : Graph Theory, Topological Sort

#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main()
{
	int N;
	cin >> N;

	vector<set<int>> g(N + 1, set<int>());
	vector<set<int>> r(N + 1, set<int>());

	for (int i = 1; i <= N; ++i)
	{
		int j;
		while (cin >> j && j != 0)
		{
			g[i].insert(j);
			r[j].insert(i);
		}
	}

	vector<bool> visited(N + 1, false);
	vector<int> topo;

	while (topo.size() != N)
	{
		int cur = 1;
		for (; cur <= N; ++cur)
			if (r[cur].empty() && !visited[cur])
				break;
		topo.push_back(cur);
		visited[cur] = true;
		for (auto x : g[cur])
			r[x].erase(cur);
	}

	for (int i = 0; i < N; ++i)
		cout << topo[i] << " ";
	cout << endl;

	return 0;
}
