#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int s;
	cin >> s;

	vector<long long> vf(s+1, 0);
	vf[0] = 1;

	for (int i = 1; i < 10; ++i)		// use first i digits
		for (int j = s; j >= 0; --j)	// ways to have sum of j
			for (int d = 1; d <= min(9, j); ++d)
					vf[j] += vf[j - d];

	cout << ((s == 1) ? (vf[s] + 1) : vf[s]) << endl;
	
	return 0;
}