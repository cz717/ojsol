/*
ID: huajian2
LANG: C++11
TASK: fence
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	ofstream fout("fence.out");
	ifstream fin("fence.in");

	vector<list<int> > graph(501);
	vector<int> de(501, 0);
	vector<int> circuit;
	stack<int> stk;

	// read
	int n, a, b;
	fin >> n;
	for (int i = 0; i != n; i++)
	{
		fin >> a >> b;
		graph[a].push_back(b);
		if (b != a)
			graph[b].push_back(a);
		de[a]++;
		de[b]++;
	}

	// sort
	for (int i = 1; i <= 500; i++)
		graph[i].sort();

	// start 
	int cur = 1;
	for (int i = 1; i <= 500; i++)
		if (de[i] % 2 == 1)
		{
			cur = i;
			break;
		}
	
	// find 
	while (cur != -1)
	{
		if (graph[cur].empty())		// no neighbor
		{
			circuit.push_back(cur);	// circuit
			if (stk.empty())
				cur = -1;
			else {
				cur = stk.top();
				stk.pop();
			}
		}
		else {
			stk.push(cur);
			cur = graph[cur].front();	// process w
			graph[stk.top()].pop_front();	// delete (v, w)
			if (cur != stk.top())			// delete (w, v)
			{
				auto& l = graph[cur];
				l.erase(find(l.begin(), l.end(), stk.top()));
			}
		}
	}

	// print
	for (auto x = circuit.rbegin(); x != circuit.rend(); x++)
		fout << *x << endl;

    return 0;
}