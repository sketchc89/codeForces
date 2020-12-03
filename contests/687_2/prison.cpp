#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int64_t n, m, r, c;
        cin >> n >> m >> r >> c;
        vi[test] = max(abs(n - r), abs(r - 1)) + max(abs(m - c), abs(c - 1));
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
