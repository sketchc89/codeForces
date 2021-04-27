#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        double n, k;
        cin >> n >> k;
        if (n > k) {
            if (static_cast<int>(n) % static_cast<int>(k) == 0) {
                vi[test] = 1;
            } else {
                vi[test] = 2;
            }
        } else if (n == k) {
            vi[test] = 1;
        } else {
            vi[test] = ceil(k / n);
        }
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
