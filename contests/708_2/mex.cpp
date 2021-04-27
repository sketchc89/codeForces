#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<vector<int>> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(begin(arr), end(arr));
        stack<int> s;
        int maxElem = -1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= maxElem) {
                s.push(arr[i]);
            } else {
                // cout << "push " << arr[i] << "\n";
                vi[test].push_back(arr[i]);
            }
            maxElem = max(maxElem, arr[i]);
        }
        while (!s.empty()) {
            vi[test].push_back(s.top());
            s.pop();
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
