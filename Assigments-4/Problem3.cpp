// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

int MinCost(vector<int>& days, vector<int>& costs)
{

	queue<pair<int, int> > qmonth;
	queue<pair<int, int> > qweek;

	int ans = 0;

	for (int day : days) {

		while (!qmonth.empty()
			&& qmonth.front().first + 30 <= day) {
			qmonth.pop();
		}

		while (!qweek.empty()
			&& qweek.front().first + 7 <= day) {
			qweek.pop();
		}

		qmonth.push(make_pair(day, ans + costs[2]));
		qweek.push(make_pair(day, ans + costs[1]));

		ans = min(ans + costs[0],
				min(qmonth.front().second,
					qweek.front().second));
	}
	return ans;
}


int main()
{
	vector<int> arr{ 2, 4, 6, 7, 8, 10, 15 };
	vector<int> cost{ 3, 108, 20 };
	cout << MinCost(arr, cost) << endl;

	return 0;
}
