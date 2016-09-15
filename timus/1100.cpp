#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

using team = pair<int,int>;

class team_comp
{
public:
	bool operator()(const team &lhs, const team &rhs)
	{
		return lhs.second > rhs.second;
	}
};

int main()
{
	int n;
	cin >> n;

	vector<team> a;
	team t;
	for (int i = 0; i < n; ++i)
	{
		cin >> t.first >> t.second;
		a.push_back(t);
	}

	team_comp tc;
	stable_sort(a.begin(), a.end(), tc);
	
	for (int i = 0; i < n; ++i)
		cout << a[i].first << ' ' << a[i].second << endl;
	
	return 0;
}
