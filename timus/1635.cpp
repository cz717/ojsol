// ID   : 1635
// Title: Mnemonics and Palindromes
// Tags : Dynamic Programming

#include <iostream>
#include <string>
using namespace std;

const int MAXN = 4001;
bool pal[MAXN][MAXN];
int cnt[MAXN];
int nxt[MAXN];

int main()
{
	string s;
	cin >> s;
	int n = s.size();

	for (int d = 0; d < n; ++d) {
		for (int i = 0; i < n - d; ++i) {
			if (d == 0)
				pal[i][i + d] = true;
			else if (d == 1)
				pal[i][i + d] = (s[i] == s[i + d]);
			else {
				if (pal[i + 1][i + d - 1] && (s[i] == s[i + d]))
					pal[i][i + d] = true;
				else
					pal[i][i + d] = false;
			}
		}
	}

	cnt[n] = 0;
	for (int i = 0; i < n; ++i)
		cnt[i] = MAXN;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j <= n; ++j) {
			if (pal[i][j - 1]) {
				if (cnt[i] > 1 + cnt[j]) {
					cnt[i] = 1 + cnt[j];
					nxt[i] = j;
				}
			}
		}
	}

	cout << cnt[0] << endl;
	for (int b = 0; b < n; b = nxt[b]) {
		for (int i = b; i < nxt[b]; ++i)
			cout << s[i];
		cout << " ";
	}

	return 0;
}