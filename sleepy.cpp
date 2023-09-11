#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;


int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int N; cin >> N;
    int order[N];
    for (int i=0; i<N; i++) {
        cin >> order[i];
    }
    int counter = 0;
    bool valid[N];
    for (int i=0; i<N; i++) {
        valid[i] = true;
    }
    for (int i=0; i<N-1; i++) {
        for (int j=i+1; j<N; j++) {
            if (order[j] < order[i]) {
                valid[i] = false;
            }
        }
    }
    for (int i=N-1; i>=0; i--) {
        if (!valid[i]) {
            counter = i + 1;
            break;
        }
    }
    cout << counter;
    return 0;
}