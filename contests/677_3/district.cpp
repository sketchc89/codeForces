#include <bits/stdc++.h>

using namespace std;

string districtConnect(const vector<int>& gangs) {
    unordered_set<int> used;
    string res = "YES\n";
    for (int i = 0; i < gangs.size(); ++i) {
        if (used.count(i)) {
            continue;
        }

        bool foundRoad = false;
        for (int j = i + 1; j < gangs.size(); ++j) {
            if (gangs[i] == gangs[j]) {
                continue;
            }
            // cout << i + 1 << ' ' << j + 1 << '\n';
            foundRoad = true;
            res += move(to_string(i + 1));
            res.push_back(' ');
            res += move(to_string(j + 1));
            res.push_back('\n');
            used.insert(j);
        }
        if (foundRoad) {
            used.insert(i);
        }
    }
    if (used.size() != gangs.size()) {
        res = "NO\n";
    }
    return res;
}

int main() {
    int tests;
    cin >> tests;
    vector<string> vs(tests);
    for (int i = 0; i < tests; ++i) {
        int numGangs;
        cin >> numGangs;
        vector<int> gangs(numGangs);
        for (int i = 0; i < numGangs; ++i) {
            cin >> gangs[i];
        }
        vs[i] = districtConnect(gangs);
    }
    for (auto str : vs) {
        cout << str;
    }
    return 0;
}
