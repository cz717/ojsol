#include <iostream>
#include <string>
using namespace std;

int main()
{
	string msg;
	cin >> msg;

	int s = msg.size();
	int i = 1;
	int j = 1;
	for (; i < s; ++i, ++j)
	{
		msg[j] = msg[i];
		if (j > 0 && msg[j] == msg[j - 1])
			j -= 2;
	}

	msg.erase(msg.begin() + j, msg.end());
	cout << msg;

	return 0;
}