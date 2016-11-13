// ID   : 1410
// Title: Crack
// Tags : dynamic programming

#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	char a;
	int n = 0;
	vector<int> v;
	while (scanf("%c", &a) != EOF) {
		if (isalpha(a))
			++n;
		else if (n > 0) {
			v.push_back(n);
			n = 0;
		}
	}
	if (n > 0)
		v.push_back(n);

	int s = v.size();
	vector<int> c(s, 0);

	for (int i = 0; i < s; ++i) {
		if (i < 2)
			c[i] = v[i];
		else if (i == 2)
			c[i] = v[i] + c[i - 2];
		else
			c[i] = v[i] + max(c[i - 2], c[i - 3]);
	}

	if (s == 0)
		printf("0\n");
	else if (s == 1)
		printf("%d\n", c[0]);
	else
		printf("%d\n", max(c[s - 1], c[s - 2]));

	return 0;
}