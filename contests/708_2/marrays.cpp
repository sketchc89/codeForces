#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    string line = string(30, '-');
    line = "\n" + line + "\n";
    for (int64_t test = 0; test < tests; ++test) {
        // cout << line << "Test " << test << line;
        int n, m;
        cin >> n >> m;
        vector<int> arr(m, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            // cout << x % m << ',';
            arr[x % m]++;
        }
        if (arr[0] > 0) {
            vi[test]++;
        }
        for (int i = 1; i < (m + 1) / 2; ++i) {
            // cout << i << ':' << m - i << '\t' << arr[i] << ':' << arr[m - i] << '\n';
            if (arr[i] == 0 && arr[m - i] == 0) {
                // cout << "Skipping " << i << '\n';
                continue;
            }
            if (abs(arr[m - i] - arr[i]) <= 1) {
                vi[test]++;
                // cout << "Added 1\n";
            } else {
                vi[test] += abs(arr[m - i] - arr[i]);
                // cout << "Added " << abs(arr[m - i] - arr[i]) << "\n";
            }
        }
        if (m % 2 == 0 && arr[m / 2] > 0) {
            vi[test]++;
        }
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
