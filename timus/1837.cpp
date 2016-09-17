#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
using namespace std;

int main()
{
	int n;
	string name[3];

	map<string, int> id_map;
	vector<list<int>> adj_list;
	int id = 0;

	// build adj_list
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> name[j];
			if (id_map.find(name[j]) == id_map.end())
			{
				id_map[name[j]] = id++;
				adj_list.push_back(list<int>());
			}
		}

		for (int v = 0; v < 2; ++v)
		{
			for (int u = v + 1; u < 3; ++u)
			{
				adj_list[id_map[name[v]]].push_back(id_map[name[u]]);
				adj_list[id_map[name[u]]].push_back(id_map[name[v]]);
			}
		}
	}

	// bfs
	queue<int> q;
	vector<bool> visited(id, false);
	vector<int> number(id, -1);

	if (id_map.find("Isenbaev") != id_map.end())
	{
		int x = id_map["Isenbaev"];
		q.push(x);
		number[x] = 0;

		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			visited[cur] = true;
			for (auto next : adj_list[cur])
			{
				if (!visited[next])
				{
					visited[next] = true;
					number[next] = number[cur] + 1;
					q.push(next);
				}
			}
		}
	}

	// print
	for (auto member : id_map)
	{
		cout << member.first << " ";
		if (number[member.second] == -1)
			cout << "undefined" << endl;
		else
			cout << number[member.second] << endl;
	}

	return 0;
}