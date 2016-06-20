/*
ID: huajian2
LANG: C++
TASK: shopping
*/

#include <iostream>
#include <fstream>

using namespace std;

// special offer
int son[100];
int soc[100][5];	// code
int sok[100][5];	// number
int sop[100];		// reduced price

int odk[100][5];	// ordered number
int rdp[100];		// 

// item to buy
int bkc[5];			// code
int bkk[5];			// number
int bkp[5];			// regular price

// dp
int mrd[6][6][6][6][6];

int main()
{
	ofstream fout("shopping.out");
	ifstream fin("shopping.in");

	int s, b;

	// read
	fin >> s;
	for (int i = 0; i != s; i++)
	{
		fin >> son[i];
		for (int j = 0; j != son[i]; j++)
			fin >> soc[i][j] >> sok[i][j];
		fin >> sop[i];
	}
	fin >> b;
	for (int i = 0; i != b; i++)
		fin >> bkc[i] >> bkk[i] >> bkp[i];

	// total price
	int regprc = 0;
	for (int i = 0; i < 5; i++)
		regprc += bkk[i] * bkp[i];

	// order
	for (int i = 0; i != s; i++)	// for every special offer
	{
		int regp = 0;
		for (int j = 0; j < son[i]; j++)	// for every item
		{
			bool ok = false;	// weather it is in the basket
			for (int k = 0; k != 5; k++)
			{
				if (bkc[k] == soc[i][j])
				{
					odk[i][k] = sok[i][j];
					regp += sok[i][j] * bkp[k];
					ok = true;
					break;
				}
			}
			if (!ok)	// not in basket
			{
				regp = sop[i];		// let rdp = 0
				break;
			}
		}
		rdp[i] = regp - sop[i];
	}

	// dinamic program
	int num[5] = { 0, 0, 0, 0, 0 };
	for (num[0] = 0; num[0] <= bkk[0]; ++num[0])
		for (num[1] = 0; num[1] <= bkk[1]; ++num[1])
			for (num[2] = 0; num[2] <= bkk[2]; ++num[2])
				for (num[3] = 0; num[3] <= bkk[3]; ++num[3])
					for (num[4] = 0; num[4] <= bkk[4]; ++num[4])
					{
						int currd = 0, maxrd = 0;
						for (int i = 0; i < s; i++)	// for every special offer
						{
							bool ok = true;
							for (int j = 0; j < 5; j++)
								if (num[j] < odk[i][j])
									ok = false;

							if (ok)
							{
								currd = rdp[i] + mrd[num[0] - odk[i][0]][num[1] - odk[i][1]][num[2] - odk[i][2]][num[3] - odk[i][3]][num[4] - odk[i][4]];
								if (currd > maxrd)
									maxrd = currd;
							}		
						}
						mrd[num[0]][num[1]][num[2]][num[3]][num[4]] = maxrd;
					}

	// print
	fout << regprc - mrd[bkk[0]][bkk[1]][bkk[2]][bkk[3]][bkk[4]] << endl;

    return 0;
}
