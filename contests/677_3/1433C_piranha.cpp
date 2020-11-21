#include <bits/stdc++.h>

using namespace std;

int piranhas(const vector<int>& fish) {
    // cout << '\n';
    int N = fish.size();
    int idx = max_element(fish.cbegin(), fish.cend()) - fish.cbegin();
    if (idx != 0 && fish[idx - 1] != fish[idx]) {
        // cout << "left\n";
        return idx + 1;
    }
    if (idx != N - 1 && fish[idx + 1] != fish[idx]) {
        // cout << "right\n";
        return idx + 1;
    }
    for (int i = idx + 1; i < N; ++i) {
        if (fish[i] == fish[idx]) {
            if (i != 0 && fish[i - 1] != fish[i]) {
                // cout << "left\n";
                return i + 1;
            }
            if (i != N - 1 && fish[i + 1] != fish[i]) {
                // cout << "right\n";
                return i + 1;
            }
            // cout << "nope\n";
        }
    }
    return -1;
}

int main() {
    int tests;
    cin >> tests;
    vector<int> vi(tests);
    for (int i = 0; i < tests; ++i) {
        int numP;
        cin >> numP;
        vector<int> fish(numP);
        for (int i = 0; i < numP; ++i) {
            cin >> fish[i];
        }
        vi[i] = piranhas(fish);
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
