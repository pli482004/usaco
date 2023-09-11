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
    int N, M; cin >> N >> M;
    vector<int> same[N];
    vector<int> diff[N];
    for (int i=0; i<N; i++) {
        string a; int b, c;
        cin >> a >> b >> c;
        if (a == "S") {
            if (b < c) same[c].push_back(b);
            else same[b].push_back(c);
        } else {
            if (b < c) diff[c].push_back(b);
            else diff[b].push_back(c);
        }
    }
    int pastures[N];
    for (int i=0; i<N; i++) {
        if (i==0) {
            pastures[0] = 0;
            continue;
        }
        vector<int> options;
        vector<int> prohibit;
        for (auto sam: same[i]) {
            options.push_back(pastures[sam]);
        }
        for (auto dif: diff[i]) {
            prohibit.push_back(pastures[dif]);
        }
        int answer = INT32_MAX;
        for (auto option: options) {
            bool ok = true;
            for (auto proh: prohibit) {
                if (proh == option) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                if (answer > ok) answer = ok;
            }
        }
    }
}