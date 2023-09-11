#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
//    freopen("citystate.in", "r", stdin);
//    freopen("citystate.out", "w", stdout);
    int N; cin >> N; map<string, int> cities; map<string, int> states;
    for (int i=0; i<N; i++) {
        string city; string state; cin >> city >> state;
        city = city[0] + city[1];
        if (not cities[city]) {
            cities[city] = 1;
        } else {
            cities[city]++;
        }
        if (not states[state]) {
            states[state] = 1;
        } else {
            states[state]++;
        }
    }
    int counter = 0;
    for (auto code: cities) {
        if (states[code.first]) {
            counter += code.second + states[code.first];
        }
    }
    cout << counter / 2;
}