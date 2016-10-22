// ID   : 2018
// Title: The Debut Album
// Tags : Dynamic Programming

#include <iostream>
using namespace std;

const int MAXN = 301;
const long long M = 1000000007;

long long x[MAXN];
long long y[MAXN];

int min(int lhs, int rhs) {
	return (lhs < rhs) ? lhs : rhs;
}

int main()
{
	int n, a, b;
	cin >> n >> a >> b;

	x[0] = y[0] = 1;
	long long s = 0;
	for (int i = 1; i <= n; ++i) {
		s = 0;
		for (int d = 1; d <= min(a,i); ++d)
			s += y[(i - d + MAXN) % MAXN];
		x[i % MAXN] = s % M;

		s = 0;
		for (int d = 1; d <= min(b, i); ++d)
			s += x[(i - d + MAXN) % MAXN];
		y[i % MAXN] = s % M;
	}

	long long sum = (x[n % MAXN] + y[n % MAXN]) % M;
	cout << sum << endl;

	return 0;
}
