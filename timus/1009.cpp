#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<long long> a(20, 0);
	vector<long long> b(20, 0);

	b[1] = K - 1;
	for (int i = 2; i <= N; ++i)
	{
		a[i] = b[i - 1];
		b[i] = b[i - 1] * (K - 1) + a[i - 1] * (K - 1);
	}
		
	cout << a[N] + b[N];
	
	return 0;
}