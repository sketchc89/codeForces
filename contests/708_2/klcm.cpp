#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<vector<int>> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int k, n;
        cin >> n >> k;
        if (n % 2 == 0) {
            if (n / 2 % 2 == 1) {
                vi[test] = {2, n / 2 - 1, n / 2 - 1};
            } else {
                vi[test] = {n / 4, n / 4, n / 2};
            }
            // cout << vi[test][0] << ',' << vi[test][1] << ',' << vi[test][2] << '\n';
        } else {
            vi[test] = {1, n / 2, n / 2};  // truncates
            // cout << vi[test][0] << ',' << vi[test][1] << ',' << vi[test][2] << '\n';
        }
    }
    for (auto&& vec : vi) {
        for (auto num : vec) {
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}
