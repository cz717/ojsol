// ID   : 1586
// Title: Threeprime Numbers
// Tags : Dynamic Programming

#include <iostream>
#include <vector>
#include <list>
using namespace std;

const long long M = 1000000009;

int main()
{
	int n;
	cin >> n;

	// find all three digit prime
	vector<bool> p(1000, true);
	for (int i = 2; i < 32; ++i) {
		if (p[i]) {
			for (int j = 2; i * j < 1000; ++j)
				p[i*j] = false;
		}
	}
	vector<int> prime;
	vector<int> index(1000, -1);
	for (int i = 100; i < 1000; ++i)
		if (p[i]) {
			index[i] = prime.size();
			prime.push_back(i);
		}
	// build graph
	int np = prime.size();
	vector<list<int>> adj(np, list<int>());
	for (int i = 0; i < np; ++i) {
		int x = (prime[i] % 100) * 10;
		if (x >= 100) {
			for (int d = 0; d < 10; ++d) {
				if (p[x + d])
					adj[i].push_back(index[x + d]);
			}
		}
	}

	// dynamic programming
	vector<vector<long long>> c(2, vector<long long>(np, 1));
	int last = 1, cur = 0;
	for (int i = 4; i <= n; ++i) {
		swap(last, cur);
		for (int j = 0; j < np; ++j) {
			long long cnt = 0;
			for (auto x : adj[j])
				cnt += c[last][x];
			c[cur][j] = cnt % M;
		}
	}

	long long sum = 0;
	for (int i = 0; i < np; ++i) {
		sum += c[cur][i];
		sum %= M;
	}

	cout << sum << endl;

	return 0;
}