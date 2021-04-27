#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int64_t n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> positions;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                positions.push_back(i);
            }
        }
        if (positions.size() <= 2) {
            vi[test] = positions.size();
            continue;
        }
        int res = 2;
        int prev = positions[0];
        int last = positions[positions.size() - 1];
        int firstChange = -1;
        int lastChange = -1;
        for (int i = 1; i < positions.size() - 1; ++i) {
            if (positions[i] - prev <= k && positions[i + 1] - prev > k) {
                prev = positions[i];
                ++res;
            } else {
                // cout << positions[i] << " left side is " << prev << " right side is " << last << "\n";
            }
        }

        vi[test] = res;
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
