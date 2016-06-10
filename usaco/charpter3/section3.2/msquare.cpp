/*
ID: huajian2
LANG: C++
TASK: msquare
*/

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int fac[9];
bool visited[40320];	// all false
int last[40320];		// path

int trans[3][8] = {
	{8, 7, 6, 5, 4, 3, 2, 1},
	{4, 1, 2, 3, 6, 7, 8, 5},
	{1, 7, 2, 4, 5, 3, 6, 8}
};

// functors
void num_to_str(int x, char *s);
int str_to_num(char *s);
void cantor(int x, char *s);
int uncantor(char * s);
int tran(char *s, int x);

int main()
{
	ofstream fout("msquare.out");
	ifstream fin("msquare.in");

	// fac
	fac[0] = 1;
	for (int i = 1; i < 9; i++)
		fac[i] = fac[i - 1] * i;

	// read
	char targ[8];
	for (int i = 0; i < 8; i++)
		fin >> targ[i];
	int tar = uncantor(targ);


	// bfs
	char s[8];
	num_to_str(12345678, s);
	int init = uncantor(s);
	last[init] = -1;

	queue<int> q;
	q.push(init);
	visited[init] = true;

	bool done = false;
	while (!done && !q.empty())
	{
		int x = q.front();
		q.pop();
	
		cantor(x, s);
		for (int i = 0; i < 3; i++)
		{
			int t = tran(s, i);
			if (!visited[t])
			{
				visited[t] = true;
				q.push(t);
				last[t] = x;
			}
			if (t == tar)
			{
				done = true;
				break;
			}
		}
	}
	
	// path
	stack<int> path;
	int n = tar;
	while (last[n] != -1)
	{
		path.push(n);
		n = last[n];
	}

	fout << path.size() << endl;

	n = init;
	while (!path.empty())
	{
		cantor(n, s);
		for (int i = 0; i < 3; i++)
		{
			if (tran(s, i) == path.top())
			{
				fout << (char)('A' + i);
				break;
			}
		}
		n = path.top();
		path.pop();
	}
	fout << endl;

	return 0;
}

void num_to_str(int x, char *s)
{
	int a = 10000000;
	int i = 0;
	while (a > 0)
	{
		s[i] = '0' + (x/a);
		x %= a;
		a /= 10;
		++i;
	}
}

int str_to_num(char *s)
{
	int x = 0;
	for (int i = 0; i < 8; i++)
	{
		x *= 10;
		x += s[i] - '0';
	}
	return x;
}

void cantor(int x, char *s)
{
	// [0, 8!-1] --> [12345678, 87654321]
	bool c[9];
	for (int i = 0; i < 9; i++)
		c[i] = false;

	for (int i = 7; i >= 0; i--)	// from 7 to 1
	{
		int a = x / fac[i] + 1;
		x %= fac[i];

		int num = 0;
		for (int j = 1; j < 9; j++)
		{
			if (c[j] == false)
				++num;
			if (num == a)
			{
				c[j] = true;
				s[7-i] = '0' + j;
				break;
			}
		}
	}
}

int uncantor(char * s)
{
	// [12345678, 87654321] --> [0, 8!-1]
	bool c[9];
	for (int i = 0; i < 9; i++)
		c[i] = false;

	int x = 0;
	for (int i = 0; i < 8; i++)	// for every char in s
	{
		int count = 0;
		for (int j = 1; j < 9; j++)
		{
			if (c[j] == false)
				++count;
			if (j == s[i] - '0')
			{
				c[j] = true;
				x += (count - 1) * fac[8 - i - 1];
				break;
			}
		}
	}
	return x;
}

int tran(char *s, int x)
{
	//  x in [0, 2]
	char t[8];
	for (int i = 0; i < 8; i++)
		t[i] = s[trans[x][i] - 1];
	return uncantor(t);
}