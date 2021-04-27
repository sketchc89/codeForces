#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<string> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int n, first, second, white, black;
        cin >> n >> first >> second;
        cin >> white >> black;
        if ((2 * white > first + second) || (2 * black > n - first + n - second)) {
            vi[test] = "NO";
        } else {
            vi[test] = "YES";
        }
    }
    for (auto&& num : vi) {
        cout << num << '\n';
    }
    return 0;
}
