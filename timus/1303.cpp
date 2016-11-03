// ID   : 1303
// Title: Minimal Coverage
// Tags : Dynamic Programming, Greedy

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

const int NINF = -50005;
const int PINF = 50005;
const int MAXN = 100005;

struct seg {
	int l, r;
};

int cmp(const void *lhs, const void *rhs) {
	seg *x = (seg *)lhs;
	seg *y = (seg *)rhs;
	if (x->l < y->l)
		return -1;
	else if (x->l == y->l)
		return 0;
	else
		return 1;
}

seg segs[MAXN];

int main()
{
	int m, l, r;
	cin >> m;

	int s;
	for (s = 0; ; ++s) {
		cin >> l >> r;
		if (l == 0 && r == 0)
			break;
		segs[s].l = l;
		segs[s].r = r;
	}

	qsort(segs, s, sizeof(seg), cmp);

	int b = NINF, e = 0;
	int p = 0;
	vector<int> cover;
	while (e < m) {
		int maxp = p;
		int maxr = NINF;
		for (; p < s && segs[p].l <= e; ++p) {
			if (maxr < segs[p].r) {
				maxr = segs[p].r;
				maxp = p;
			}
		}
		if (maxr < e) {
			cout << "No solution" << endl;
			return 0;
		}
		else {
			cover.push_back(maxp);
			b = e;
			e = maxr;
		}
	}

	cout << cover.size() << endl;
	for (int i = 0; i < cover.size(); ++i)
		cout << segs[cover[i]].l << " " << segs[cover[i]].r << endl;

	return 0;
}