#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> adj(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> adj[i];
		if (adj[i])
		{
			int temp;
			while (cin >> temp && temp != 0);
		}
	}

	// 1 for set A, 2 for set B
	vector<int> set(n + 1, 0);
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (set[i])
			continue;
		else if (adj[i] == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		else
		{
			int j = adj[i];
			if (set[j] == 1)
				set[i] = 2;
			else if (set[j] == 2)
			{
				set[i] = 1;
				++cnt;
			}
			else
			{
				set[i] = 1;
				set[j] = 2;
				++cnt;
			}
		}
	}

	cout << cnt << endl;
	for (int i = 1; i <= n; ++i)
		if (set[i] == 1)
			cout << i << " ";
	cout << endl;

	return 0;
}
