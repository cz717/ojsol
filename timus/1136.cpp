#include <iostream>
#include <vector>
using namespace std;

void odd_to_even(int odd[], int b, int e)
{
	if (b > e)
		return;
	else if (b == e)
	{
		cout << odd[e] << endl;
		return;
	}
	else
	{
		int left = e - 1;
		for (; left >= b && odd[left] > odd[e]; --left);
		int right = e - 1;

		odd_to_even(odd, left + 1, right);
		odd_to_even(odd, b, left);
		cout << odd[e] << endl;
	}
}

int main()
{
	int n;
	int odd[3000];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> odd[i];

	odd_to_even(odd, 0, n - 1);

	return 0;
}
