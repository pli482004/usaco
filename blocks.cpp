#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int N; cin >> N;
    pair<string, string> words[N];
    for (int i=0; i<N; i++) {
        cin >> words[i].first >> words[i].second;
    }
    int alphabet[26] = {0};

    for (const auto& board: words) {
        int alp1[26] = {0};
        int alp2[26] = {0};
        for (char cha: board.first) {
            alp1[cha - 'a']++;
        }
        for (char cha: board.second) {
            alp2[cha - 'a']++;
        }
        for (int i=0; i<26; i++) {
            if (alp1[i] > alp2[i]) {
                alphabet[i] += alp1[i];
            } else if (alp1[i] < alp2[i]) {
                alphabet[i] += alp2[i];
            } else {
                alphabet[i] += alp1[i];
            }
        }
    }
    for (int i=0; i<26; i++) {
        cout << alphabet[i] << endl;
    }
}