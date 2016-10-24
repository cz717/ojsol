// ID   : 1017
// Title: Staircases
// Tags : Dynamic Programming

#include <iostream>
using namespace std;

long long q[501][501];

int main()
{
	int n;
	cin >> n;

	for (int j = n; j > 0; --j) {
		for (int i = n; i > 0; --i) {
			if (j > i)
				q[i][j] = 0;
			else if (j == i)
				q[i][j] = 1;
			else 
				q[i][j] = q[i - j][j + 1] + q[i][j + 1];
		}
	}
	cout << q[n][1] - 1 << endl;

	return 0;
}