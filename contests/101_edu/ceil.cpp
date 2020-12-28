#include <bits/stdc++.h>
using namespace std;

int main() {
    // i/o

    int N;
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        cin >> N;
        vector<pair<int, int>> ops;
        int num = N;
        while (num > 2) {
            int root = ceil(sqrt(num));
            for (int i = root + 1; i < num; ++i) {
                ops.emplace_back(make_pair(i, i + 1));
            }
            ops.emplace_back(make_pair(num, root));
            ops.emplace_back(make_pair(num, root));
            num = root;
        }

        cout << ops.size() << '\n';
        for (auto&& p : ops) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }

    return EXIT_SUCCESS;
}
