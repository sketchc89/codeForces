#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int n;
        cin >> n;
        vector<int> v(n);
        unordered_map<int, int> count;
        for (int i = 0; i < v.size(); ++i) {
            cin >> v[i];
            count[v[i]]++;
        }
        int mostFreq = -1;
        int mostFreqVal = -1;
        for (auto&& kv : count) {
            if (kv.second >= mostFreq) {
                mostFreq = kv.second;
                mostFreqVal = kv.first;
            }
        }
        // cout << "Most frequent value is " << mostFreqVal << " at " << mostFreq << "\n";
        for (auto&& kv : count) {
            if (kv.first != mostFreqVal) {
                // cout << "Subtracting " << kv.second << " by matching " << kv.first << "\n";
                mostFreq -= kv.second;
            }
        }
        // cout << "Most frequent value is now " << mostFreqVal << " at " << mostFreq << "\n";
        vi[test] = max(0, mostFreq);
        if (vi[test] % 2 == 0 && n % 2 == 1) {
            vi[test]++;
        }
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
