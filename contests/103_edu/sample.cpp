#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int64_t x, y;
        cin >> x >> y;
        vi[test] = max(ceil(x / y), ceil(y / x));
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
