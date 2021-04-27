#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<string> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        string s;
        cin >> s;
        bool fail = false;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '1' && s[i + 1] == '1') {
                // cout << "Two ones at " << i << '\n';
                if (s.find("00", i) != string::npos) {
                    fail = true;
                }
                break;
            }
        }
        reverse(begin(s), end(s));
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0' && s[i + 1] == '0') {
                // cout << "Two zeros at " << i << '\n';
                if (s.find("11", i) != string::npos) {
                    fail = true;
                }
                break;
            }
        }
        if (fail) {
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
