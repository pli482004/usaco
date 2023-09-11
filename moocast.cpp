#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int positions[100]
int num_destroyed = 0

void explode(int current, int time)

int main () {
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        cin >> positions[i];
    }
    sort(positions.begin(), positions.end());
    for (int i=0; i<N; i++) {
        num_destroyed = 0;
        explode(i, 1);
    }
}
