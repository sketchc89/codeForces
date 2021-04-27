#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<string> vs(tests);
    for (int64_t test = 0; test < tests; ++test) {
        string s;
        cin >> s;
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (count[c] <= 1) {
                continue;
            }
            bool used = false;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != c) {
                    continue;
                }
                if (i == s.size() - 1 || s[i] <= s[i + 1] || used) {
                    s[i] = '{';
                    count[c]--;
                } else {
                    used = true;
                }

                if (count[c] == 1) {
                    break;
                }
            }
        }
        string res = "";
        for (char c : s) {
            if (c != '{') {
                res.push_back(c);
            }
        }
        vs[test] = res;
    }
    for (auto&& s : vs) {
        cout << s << '\n';
    }
    return 0;
}
