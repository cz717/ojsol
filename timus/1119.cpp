#include <iostream>
#include <cmath>
using namespace std;

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

double pos[1001][1001];
const double diag = sqrt(2);

int main()
{
	int N, M, K;
	int x, y;
	
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		cin >> x >> y;
		pos[x][y] = 1;
	}

	for (int i = 0; i <= N; ++i)
		pos[i][0] = i;
	for (int j = 0; j <= M; ++j)
		pos[0][j] = j;

	double m;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			m = MIN(pos[i - 1][j], pos[i][j - 1]) + 1;
			if (pos[i][j] == 1)
				m = MIN(pos[i - 1][j - 1] + diag, m);
			pos[i][j] = m;
		}

	cout << (int)(pos[N][M] * 100 + 0.5) << endl;

	return 0;
}