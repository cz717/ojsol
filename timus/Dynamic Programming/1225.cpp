#include <iostream>
using namespace std;

int main()
{
	int n;
	long long w[45], r[45];

	cin >> n;
	w[0] = r[0] = 1;
	w[1] = r[1] = 1;
	for (int i = 2; i < n; ++i)
	{
		w[i] = r[i - 1] + r[i - 2];
		r[i] = w[i - 1] + w[i - 2];
	}
	cout << r[n - 1] + w[n - 1] << endl;
	// 2 * fab(n-1)

	return 0;
}