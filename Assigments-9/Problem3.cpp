#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    map<int, int> permits;
    for (int i = 0; i < K; i++) {
        int X, Y;
        cin >> X >> Y;
        permits[Y] = X;  // Store the permitted truck for each road
    }

    vector<int> capacity(M);
    for (int i = 0; i < M; i++) {
        cin >> capacity[i];
    }

    int Z;
    cin >> Z;

    for (int i = 0; i < Z; i++) {
        int R, P;
        cin >> R >> P;

        int max_trucks = 0;
        capacity[R - 1] -= P;

        // Check the permitted truck for road R
        int truck_on_road = permits[R];

        if (truck_on_road <= capacity[R - 1]) {
            max_trucks = truck_on_road;
        } else {
            max_trucks = capacity[R - 1];
        }

        cout << max_trucks << endl;
    }

    return 0;
}
