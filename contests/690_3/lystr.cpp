#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<string> vi(tests);
    for (int test = 0; test < vi.size(); ++test) {
        int _n;
        cin >> _n;  // unused
        string s;
        cin >> s;
        auto pos = s.find("2020");
        if (pos == 0 || pos == s.size() - 4) {
            vi[test] = "YES";
            continue;
        }
        pos = s.find("2020", s.size() - 4);
        if (pos == s.size() - 4) {
            vi[test] = "YES";
            continue;
        }

        pos = s.find("2");
        if (pos == 0 && s.find("020", s.size() - 3) != string::npos) {
            vi[test] = "YES";
            continue;
        }

        pos = s.find("20");
        if (pos == 0 && s.find("20", s.size() - 2) != string::npos) {
            vi[test] = "YES";
            continue;
        }

        pos = s.find("202");
        if (pos == 0 && s.find("0", s.size() - 1) != string::npos) {
            vi[test] = "YES";
            continue;
        }
        vi[test] = "NO";
    }
    for (auto num : vi) {
        cout << num << '\n';
    }


    return 0;
}
