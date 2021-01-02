#include <bits/stdc++.h>
using namespace std;

int main() {
    // i/o

    int tests;
    cin >> tests;
    vector<int> res(tests);

    for (int test = 0; test < tests; ++test) {
        int numTrees;
        cin >> numTrees;
        vector<int> trees(numTrees);
        for (int tree = 0; tree < trees.size(); ++tree) {
            cin >> trees[tree];
        }
        sort(begin(trees), end(trees));
        unordered_set<int> diffs;
        for (int i = 0; i < trees.size(); ++i) {
            for (int j = i + 1; j < trees.size(); ++j) {
                diffs.insert(trees[j] - trees[i]);
            }
        }

        res[test] = diffs.size();  //
    }
    for (auto t : res) {
        cout << t << '\n';
    }

    return EXIT_SUCCESS;
}
