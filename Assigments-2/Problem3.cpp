#include <bits/stdc++.h>
using namespace std;

using namespace std;

struct Road {
    int house1;
    int house2;
    int cost;
};

bool compareRoads(const Road& road1, const Road& road2) {
    return road1.cost < road2.cost;
}

int findParent(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);

    if (rank[xRoot] < rank[yRoot])
        parent[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
        parent[yRoot] = xRoot;
    else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

int findMinExpense(int n, int m, vector<Road>& roads) {
    sort(roads.begin(), roads.end(), compareRoads);

    vector<int> parent(n);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; ++i)
        parent[i] = i;

    int totalCost = 0;
    for (const auto& road : roads) {
        int house1 = road.house1 - 1;
        int house2 = road.house2 - 1;
        int cost = road.cost;

        int root1 = findParent(parent, house1);
        int root2 = findParent(parent, house2);

        if (root1 != root2) {  // If adding this road doesn't form a cycle, include it
            totalCost += cost;
            unionSets(parent, rank, root1, root2);
        }
    }

    return totalCost;
}

int main() {
    int n = 5;
    int m = 6;
    vector<Road> roads = {
        {1, 2, 6},
        {2, 3, 5},
        {3, 4, 4},
        {1, 4, 1},
        {1, 3, 2},
        {3, 5, 3}
    };

    int result = findMinExpense(n, m, roads);
    cout << result << endl;  // Output: 11

    return 0;
}
