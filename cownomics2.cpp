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
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int N, M; cin >> N >> M;
    string spotty[N];
    string plain[N];
    for (int i=0; i<N; i++) {
        cin >> spotty[i];
    }
    for (int i=0; i<N; i++) {
        cin >> plain[i];
    }
    int counter = 0;
    for (int i=0; i<M-2; i++) {
        for (int j=i+1; j<M-1; j++) {
            for (int k=j+1; k<M; k++) {
                set<string> already;
                for (auto cow: spotty) {
                    string dna = "";
                    dna += cow[i];
                    dna += cow[j];
                    dna += cow[k];
                    already.insert(dna);
                }
                bool okay = true;
                for (auto cow: plain) {
                    if (okay){
                        string dna = "";
                        dna += cow[i];
                        dna += cow[j];
                        dna += cow[k];
                        if (already.count(dna) > 0) {
                            okay = false;
                        }
                    }
                }
                if (okay) counter++;
            }
        }
    }
    cout << counter;
}
