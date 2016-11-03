// ID   : 1346
// Title: Intervals of Monotonicity
// Tags : greedy, dynamic programming

#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b;
	c = b - a + 1;

	int m = 0;	// +1 for increase, -1 for decrease
	int cnt = 1;
	int last, cur;
	cin >> last;
	for (int i = 0; i < c - 1; ++i) {
		cin >> cur;
		int d = cur - last;
		if (d == 0)
			continue;
		else if (m == 0)
			m = (d > 0) ? 1 : -1;
		else if (d * m < 0) {
			m = 0;
			++cnt;
		}
		last = cur;
	}

	cout << cnt << endl;
	return 0;
}