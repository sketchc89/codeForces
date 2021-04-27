#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int chains;
        cin >> chains;
        vector<int64_t> chainLen(chains), a(chains), b(chains);
        for (int i = 0; i < chainLen.size(); ++i) {
            cin >> chainLen[i];
            --chainLen[i];
        }
        for (int i = 0; i < a.size(); ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < b.size(); ++i) {
            cin >> b[i];
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
            }
        }
        int64_t maxLen = 0, curChain = 0;
        for (int i = chainLen.size() - 1; i > 0; --i) {
            curChain = chainLen[i] + 2;
            for (int j = i - 1; j >= 0; --j) {
                // just the current chain and previous chain
                maxLen = max(maxLen, curChain + b[j + 1] - a[j + 1]);
                // cout << "Max Len starting at chain " << i << " ending at chain " << j << " is " << maxLen << "\t";
                // cout << "CurChain: " << curChain << " + " << b[j + 1] << " - " << a[j + 1] << "\n";
                if (a[j + 1] == b[j + 1]) {
                    break;
                }
                curChain += a[j + 1] + chainLen[j] - b[j + 1] + 2;
            }
        }
        vi[test] = maxLen;
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
