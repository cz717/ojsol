// ID   : 1203
// Title: Scientific Conference
// Tags : Greedy, Dynamic Programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct conf {
	int s;
	int e;
	conf(int a, int b) : s(a), e(b) {};
};

class cmp {
public:
	bool operator()(const conf &lhs, const conf &rhs) {
		return lhs.e < rhs.e;
	}
};

int main()
{
	int n;
	cin >> n;

	vector<conf> c;
	int s, e;
	for (int i = 0; i < n; ++i) {
		cin >> s >> e;
		c.push_back(conf(s, e));
	}

	// sort by end time
	sort(c.begin(), c.end(), cmp());

	int max = 0;
	int cure = 0;
	for (int i = 0; i < n; ++i) {
		if (c[i].s > cure) {
			++max;
			cure = c[i].e;
		}
	}

	cout << max << endl;

	return 0;
}
