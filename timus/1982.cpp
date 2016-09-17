#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// edge
struct edge
{
	int a;
	int b;
	int cost;
	edge(int a_, int b_, int c_)
		: a(a_), b(b_), cost(c_) {};
};

class edge_comp
{
public:
	bool operator()(edge &lhs, edge &rhs)
	{
		return (lhs.cost > rhs.cost);
	}
};

// union-find
int find(vector<int> &sets, int x)
{
	if (sets[x] != x)
		return (sets[x] = find(sets, sets[x]));
	else
		return x;
}

int uni(vector<int> &sets, int a, int b)
{
	int x = find(sets, a);
	int y = find(sets, b);
	sets[x] = y;
	return y;
}


int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> set(n, 0);
	vector<vector<int>> matrix(n, vector<int>(n));
	priority_queue<edge, vector<edge>, edge_comp> q;

	// set
	for (int i = 0; i < n; ++i)
		set[i] = i;
	int temp, first;
	cin >> first;
	--first;
	for (int i = 1; i < k; ++i)
	{
		cin >> temp;
		set[temp - 1] = first;
	}

	// matix
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> matrix[i][j];

	// priority queue
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			q.push( edge(i, j, matrix[i][j]) );
	
	// kruslal algorithm
	int min_cost = 0;
	while (!q.empty())
	{
		edge e = q.top(); q.pop();
		if (find(set, e.a) != find(set, e.b))
		{
			min_cost += e.cost;
			uni(set, e.a, e.b);
		}
	}

	cout << min_cost << endl;

	return 0;
}