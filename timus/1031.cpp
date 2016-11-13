// ID   : 1031
// Title: Railway Tickets
// Tags : dynamic programming

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10005;
const long long INF = 20000000000000;

long long l[3], c[3];
long long d[MAXN];
long long m[MAXN];
int n, b, e;

int main()
{
	for (int i = 0; i < 3; ++i)
		cin >> l[i];
	for (int i = 0; i < 3; ++i)
		cin >> c[i];
	cin >> n >> b >> e;
	if (b > e)
		swap(b, e);

	d[1] = 0;
	for (int i = 2; i <= n; ++i)
		cin >> d[i];

	m[b] = 0; 
	for (int i = b + 1; i <= e; ++i) {
		m[i] = INF;
		long long dis;
		for (int j = i - 1; j >= b && (dis = d[i] - d[j]) <= l[2] ;--j) {
			for (int k = 0; k < 3; ++k) {
				if (dis <= l[k]) {
					if (m[i] > m[j] + c[k])
						m[i] = m[j] + c[k];
					break;
				}
			}
		}
	}

	cout << m[e] << endl;
	return 0;
}
