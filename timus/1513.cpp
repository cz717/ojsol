// ID   : 1513
// Title: Lemon Tale
// Tags : dynamic programming

#include <iostream>
using namespace std;

const int BASE = 100000000;
const int WIDTH = 8;
const int LENGTH = 400;

const int MAXN = 10001;
int b[MAXN][LENGTH];
int l[MAXN][LENGTH];
int reg[LENGTH];

void add(int *x, int *y) {
	int c = 0, s = 0;
	for (int i = 0; i < LENGTH; ++i) {
		s = x[i] + y[i] + c;
		reg[i] = s % BASE;
		c = s / BASE;
	}
	if (c > 0)
		cout << "!!!!" << endl;
}

// x > y
void sub(int *x, int *y) {
	int b = 0;
	for (int i = 0; i < LENGTH; ++i) {
		if (x[i] - b < y[i]) {
			reg[i] = BASE - y[i] + x[i] - b;
			b = 1;
		}
		else {
			reg[i] = x[i] - b - y[i];
			b = 0;
		}
	}
}

void assig(int *x, int *y) {
	for (int i = 0; i < LENGTH; ++i)
		x[i] = y[i];
}

void print(int *x) {
	int h = LENGTH - 1;
	while (x[h] == 0)
		--h;
	if (h < 0) h = 0;

	for (int i = h; i >= 0; --i) {
		if (i != h) {
			int b = BASE / 10;
			for (;b != 1 && x[i] < b; b /= 10)
				cout << '0';
		}
		cout << x[i];
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	b[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		add(b[i - 1], l[i - 1]);
		assig(b[i], reg);
		assig(l[i], reg);
		if (i > k) {
			sub(l[i], b[i - k - 1]);
			assig(l[i], reg);
		}
	}

	add(b[n], l[n]);
	print(reg);
	cout << endl;

	return 0;
}