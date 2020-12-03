#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    cin.ignore(numeric_limits<int>::max(), '\n');
    for (int64_t test = 0; test < tests; ++test) {
        string s;
        getline(cin, s);
        vi[test] = s.size();
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
