#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> c(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		int min = i, cur;
		for (int j = 1; j * j <= i; ++j)
		{
			cur = c[i - j * j] + 1;
			min = (min > cur) ? cur : min;
		}
		c[i] = min;
	}
	
	cout << c[n] << endl;

	return 0;
}