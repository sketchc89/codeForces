#include <bits/stdc++.h>

using namespace std;


int main() {
    int tests;
    cin >> tests;
    vector<vector<int>> permutations(tests);

    for (int i = 0; i < tests; ++i) {
        int sz;
        cin >> sz;
        for (int j = 1; j <= sz; ++j) {
            permutations[i].push_back(j);
        }
        rotate(permutations[i].begin(), permutations[i].begin() + 1, permutations[i].end());
    }

    for (auto&& perm : permutations) {
        for (int i : perm) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
