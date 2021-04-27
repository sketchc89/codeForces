#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        string a, b;
        cin >> a >> b;
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

        for (int i = 1; i <= a.size(); ++i) {
            for (int j = 1; j <= b.size(); ++j) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    vi[test] = max(vi[test], dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        // cout << "Longest common substring is " << vi[test] << '\n';
        vi[test] = a.size() + b.size() - 2 * vi[test];
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
