#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int par, bool isBlack,
		vector<vector<int> >& adj)
{
	int no_Of_Black = isBlack;
	for (int i : adj[node]) {
		if (i == par)
			continue;

		no_Of_Black
			+= dfs(i, node, !isBlack, adj);
	}
	return no_Of_Black;
}

long long maxEdges(int n,
				vector<pair<int, int> > edges)
{
	vector<vector<int> > adj(n + 1);
	for (auto i : edges) {
		adj[i.first].push_back(i.second);
		adj[i.second].push_back(i.first);
	}

	int no_Of_Black = dfs(1, 0, 1, adj);

	int no_Of_White = n - no_Of_Black;

	return (1LL * (no_Of_Black)
				* (no_Of_White)
			- (n - 1));
}

int main()
{
	int N = 4;
	vector<pair<int, int> > edges
		= { { 1, 2 }, { 2, 3 }, { 1, 4 } };
	cout << maxEdges(N, edges) << endl;
	return 0;
}