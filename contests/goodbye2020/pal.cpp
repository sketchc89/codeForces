#include <bits/stdc++.h>
using namespace std;

int main() {
    // i/o

    int tests;
    cin >> tests;
    vector<int> res(tests);

    for (int test = 0; test < tests; ++test) {
        string s;
        cin >> s;
        vector<int> changes(s.size(), 0);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1] && !changes[i - 1]) {
                changes[i] = 1;
            }
            if (i > 1 && s[i] == s[i - 2] && !changes[i - 2]) {
                changes[i] = 1;
            }
        }
        res[test] = accumulate(begin(changes), end(changes), 0);
    }
    for (auto t : res) {
        cout << t << '\n';
    }

    return EXIT_SUCCESS;
}
