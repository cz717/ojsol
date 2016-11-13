// ID   : 1183
// Title: Brackets Sequence
// Tags : dynamic programming

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int c[MAXN][MAXN];
string s;

void print(int i, int j) {
	if (i == j)
		return;
	if (i + 1 == j) {
		switch (s[i]) {
		case '(':
		case ')':
			cout << "()";
			break;
		case '[':
		case ']':
			cout << "[]";
			break;
		}
	}
	else {
		if ((s[i] == '(' && s[j - 1] == ')' || s[i] == '[' && s[j - 1] == ']')
			&& c[i][j] == c[i + 1][j - 1]) {
			cout << s[i];
			print(i + 1, j - 1);
			cout << s[j - 1];
		}
		else {
			for (int k = i + 1; k < j; ++k) {
				if (c[i][j] == c[i][k] + c[k][j]) {
					print(i, k);
					print(k, j);
					break;
				}
			}
		}
	}
}

int main()
{
	cin >> s;
	int n = s.size();

	if (n == 0)
		return 0;

	for (int d = 0; d <= n; ++d) {
		for (int i = 0; i <= n - d; ++i) {
			int j = i + d;
			if (d == 0)
				c[i][j] = 0;
			else if (d == 1)
				c[i][j] = 1;
			else {
				c[i][j] = MAXN;
				if (s[i] == '(' && s[j - 1] == ')' ||
					s[i] == '[' && s[j - 1] == ']')
					c[i][j] = c[i + 1][j - 1];
				for (int k = i + 1; k < j; ++k)
					c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
			}
		}
	}

	print(0, n);
	
	return 0;
}