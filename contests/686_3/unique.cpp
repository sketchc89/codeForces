#include <bits/stdc++.h>

using namespace std;


int main() {
    int tests;
    cin >> tests;
    vector<int> vi(tests);

    int val;
    for (int i = 0; i < tests; ++i) {
        int bids;
        cin >> bids;
        set<int> disallowed;
        map<int, int> allowed;

        for (int bid = 0; bid < bids; ++bid) {
            cin >> val;
            if (disallowed.count(val)) {
                continue;
            } else if (allowed.count(val)) {
                allowed.erase(val);
                disallowed.insert(val);
            } else {
                allowed.emplace(make_pair(val, bid + 1));
            }
        }
        vi[i] = allowed.size() == 0 ? -1 : (allowed.begin())->second;
    }

    for (int num : vi) {
        cout << num << '\n';
    }
    return 0;
}
