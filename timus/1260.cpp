// ID   : 1260
// Title: Nudnik Photographer
// Tags : Dynamic Programming

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	long long c[60];
	c[1] = 1;
	c[2] = 1;
	c[3] = 2;
	for (int i = 4; i <= n; ++i)
		c[i] = c[i - 1] + c[i - 3] + 1;

	cout << c[n];
	return 0;
}