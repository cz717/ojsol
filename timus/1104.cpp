#include <iostream>
#include <cctype>
using namespace std;

int ctoi(char c)
{
	if (isdigit(c))
		return (c - '0');
	else if (isupper(c))
		return (c - 'A' + 10);
	else
		return -1;
}

int main()
{
	char c;
	int num;
	int max = 1;
	int sum = 0;

	while (cin >> c)
	{
		num = ctoi(c);
		if (num == -1)
			break;
		if (num > max)
			max = num;
		sum += num;
	}

	for (int k = max + 1; k <= 36; ++k)
	{
		if (sum % (k - 1) == 0)
		{
			cout << k << endl;
			return 0;
		}
	}

	cout << "No solution." << endl;
	return 0;
}