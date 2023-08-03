#include <bits/stdc++.h>
using namespace std;

double inf = std::
	numeric_limits<double>::infinity();
double solver(int s, int d,
			vector<pair<pair<int, int>,
						double> >
				ed,
			int n)
{
	if (s == d)
		return 0;
	double arr[n + 1];
	for (int i = 1; i <= n; i++)
		arr[i] = inf;
	arr[s] = 1;
	for (int i = 0; i < n - 1; i++)
		for (auto it : ed)
			arr[it.first.second] = min(arr[it.first.second],
									arr[it.first.first]
										* it.second);

	for (auto it : ed) {
		if (arr[it.first.second]
			> arr[it.first.first] * it.second)
			return -2;
	}
	if (arr[d] == inf)
		return -1;
	else
		return arr[d];
}


int main()
{

	int n , e , s , d;
    cin >> n >> e >> s >>d;

	vector<pair<pair<int, int>, double> > ed;


     for (int i = 0; i < e; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        ed.push_back({{u, v}, weight});
    }


	double res = solver(s, d, ed, n);

	if (res == -2)
		cout << "Cycle Detected";
	else
		cout << res;
}
