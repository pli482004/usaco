#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

vector<int> connections[101];
// 0 = yes, -1 = not yet visited
int connected[101][101];

void dfs(int current, int start) {
    for (auto neighbor: connections[current]) {
        connected[start][neighbor] = 0;
    }
}

int main() {
    int N; cin >> N;
    for (int i=0; i<N-1; i++) {
        int a; int b;
        cin >> a >> b;
        connections[a].push_back(b);
    }
    for (int i=1; i<101; i++) {
        for (int j=1; j<101; j++) {
            connected[i][j] = false;
        }
    }
    for (int i=1; i<=N; i++) {
        dfs(i, i);
    }
}
