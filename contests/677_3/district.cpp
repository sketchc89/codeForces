#include <bits/stdc++.h>

using namespace std;

string districtConnect(const vector<int>& gangs) {
    unordered_set<int> used;
    /* If all equal then impossible to connect */
    if (equal(gangs.cbegin() + 1, gangs.cend(), gangs.cbegin())) {
        return "NO\n";
    }
    /* If not all equal, then connect the first district to every other district
     * that isn't controlled by the first district gang,
     * then connect the rest of the first district gang territory to any neighbor
     */
    string res = "YES\n";
    int connected = -1;
    for (int i = 1; i < gangs.size(); ++i) {
        if (gangs[0] == gangs[i]) {
            continue;
        }
        if (connected == -1) {
            connected = i;
        }
        res.push_back('1');
        res.push_back(' ');
        res += move(to_string(i + 1));
        res.push_back('\n');
    }
    for (int i = 1; i < gangs.size(); ++i) {
        if (gangs[i] == gangs[0]) {
            res += move(to_string(connected + 1));
            res.push_back(' ');
            res += move(to_string(i + 1));
            res.push_back('\n');
        }
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
