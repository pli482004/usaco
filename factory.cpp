#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool connected[101][101];
vector<int> connections[101];

void dfs(int initial, int current) {
    if (connected[initial][current]) {
        return;
    }
    connected[initial][current] = true;
    for (auto neighbor: connections[current]) {
        dfs(initial, neighbor);
    }
}

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int N; cin >> N;
    for (int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
    }
    for (int i=1; i<=N; i++) {
        dfs(i, i);
    }
    for (int i=1; i<=N; i++) {
        bool good = true;
        for (int j=1; j<=N; j++) {
            if (not connected[j][i]) {
                good = false;
            }
        }
        if (good) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}