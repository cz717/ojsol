// ID   : 1078
// Title: Segments
// Tags : dynamic programming, longest increasing subsequences

#include <iostream>
#include <stack>
#include <cstdlib>	// for abs, qsort
using namespace std;

const int MAXN = 505;
const int INF = 20000;

struct seg {
	int num;
	int b, e;
};

int cmp(const void *lhs, const void *rhs) {
	seg *x = (seg *)lhs;
	seg *y = (seg *)rhs;
	return abs(x->e - x->b) - (abs(y->e - y->b));
}

seg s[MAXN];
int maxl[MAXN];
int last[MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		s[i].num = i;
		cin >> s[i].b >> s[i].e;
	}
	qsort(s + 1, n, sizeof(seg), cmp);
	
	int m = 0, e = 1;
	for (int i = 1; i <= n; ++i) {
		maxl[i] = 1;
		last[i] = 0;
		for (int j = 1; j < i; ++j) {
			if (s[i].b < s[j].b && s[j].e < s[i].e) {
				if (maxl[i] < maxl[j] + 1) {
					maxl[i] = maxl[j] + 1;
					last[i] = j;
				}
			}
		}
		if (m < maxl[i]) {
			m = maxl[i];
			e = i;
		}
	}

	cout << m << endl;
	stack<int> stk;
	while (e != 0) {
		stk.push(s[e].num);
		e = last[e];
	}
	while (!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}

	return 0;
}