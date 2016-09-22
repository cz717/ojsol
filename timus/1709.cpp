// ID   : 1709
// Title: Penguin-Avia
// Tags : Graph Theory, Spanning Tree, Union-Find Set

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 100;
int matrix[MAXN][MAXN];
int plan[MAXN][MAXN];
int ufset[MAXN];

int find(int x)
{
	if (ufset[x] != x)
		return ufset[x] = find(ufset[x]);
	else
		return x;
}

int uni(int x, int y)
{
	int a = find(x);
	int b = find(y);
	ufset[a] = b;
	return b;
}

int main()
{
	int n;
	long long d, a;
	string s;
	char c;
	cin >> n >> d >> a;
	getline(cin, s);
	for (int i = 0; i < n; ++i) {
		getline(cin, s);
		for (int j = 0; j < n; ++j)
			matrix[i][j] = s[j] - '0';
	}

	for (int i = 0; i < n; ++i)
		ufset[i] = i;

	int comp = n;
	int dcnt = 0, acnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (matrix[i][j]) {
				if (find(i) != find(j)) {
					uni(i, j);
					--comp;
				}
				else {
					matrix[i][j] = matrix[j][i] = 0;
					plan[i][j] = plan[j][i] = 1;
					++dcnt;
				}
			}
		}
	}

	if (comp > 1) {
		for (int i = 1; i < n; ++i) {
			if (find(0) != find(i)) {
				uni(0, i);
				plan[0][i] = plan[i][0] = 2;
				++acnt;
			}
		}
	}

	cout << dcnt * d + acnt * a << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			switch (plan[i][j]) {
			case 0:
				cout << 0;
				break;
			case 1:
				cout << 'd';
				break;
			case 2:
				cout << 'a';
				break;
			}
		}
		cout << endl;
	}
	return 0;
}
