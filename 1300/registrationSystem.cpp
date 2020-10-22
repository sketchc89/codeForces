#include <bits/stdc++.h>

using namespace std;
// ios_base::sync_with_stdio(false);
// cin.tie(nullptr);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, int> db;
    ostringstream oss;

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        auto it = db.find(s);
        if (it == db.end()) {
            db[s] = 0;
            oss << "OK\n";
        } else {
            db[s]++;
            oss << s + to_string(db[s]) << '\n';
        }
    }
    cout << oss.str();
    return 0;
}
