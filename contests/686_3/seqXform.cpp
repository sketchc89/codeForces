#include <bits/stdc++.h>

using namespace std;

int uniqueDeletions(vector<int>& vi) {

    vi.erase(unique(vi.begin(), vi.end()), vi.end());
    int N = vi.size();
    if (N <= 1) {
        // cout << "unique\n";
        return 0;
    }
    unordered_map<int, int> counter;
    for (auto num : vi) {
        counter[num]++;
    }

    int minElement = INT32_MAX;
    // cout << '\n';
    for (auto&& kv : counter) {
        int val = kv.second;
        if (kv.first != vi[0] && kv.first != vi[N - 1]) {
            val += 1;
        } else if (kv.first != vi[0] || kv.first != vi[N - 1]) {
            // val += 1;
        } else {
            val -= 1;
        }
        // cout << kv.first << ':' << kv.second << '=' << val << '\n';
        minElement = min(minElement, val);
    }
    return max(1, minElement);
}

int main() {
    int tests;
    cin >> tests;
    vector<int> vi(tests);

    for (int i = 0; i < tests; ++i) {
        int len;
        cin >> len;
        vector<int> values(len);
        for (int j = 0; j < values.size(); ++j) {
            cin >> values[j];
        }
        vi[i] = uniqueDeletions(values);
    }

    for (int num : vi) {
        cout << num << '\n';
    }
    return 0;
}
