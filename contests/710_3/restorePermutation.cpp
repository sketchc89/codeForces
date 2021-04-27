#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests;
    cin >> tests;
    vector<vector<vector<int>>> vvvi(tests, vector<vector<int>>(2));
    for (int64_t test = 0; test < tests; ++test) {
        int n;
        cin >> n;
        vector<int> perm(n);
        set<int> slo, shi;
        for (int i = 0; i < perm.size(); ++i) {
            slo.insert(i + 1);
            shi.insert(i + 1);
            cin >> perm[i];
        }
        vector<int> lowest(n), highest(n);
        lowest[0] = perm[0];
        slo.erase(perm[0]);
        highest[0] = perm[0];
        shi.erase(perm[0]);
        for (int i = 1; i < perm.size(); ++i) {
            if (perm[i] != perm[i - 1]) {
                lowest[i] = perm[i];
                highest[i] = perm[i];
                slo.erase(perm[i]);
                shi.erase(perm[i]);
            } else {
                int lo = *begin(slo);
                lowest[i] = lo;
                slo.erase(lo);

                // cout << "Searching for the highest number before " << perm[i] << "\n";
                // cout << "Going to segfault now :(\n";
                // auto hi = shi.lower_bound(perm[i]);
                // cout << "Hi, lower bound is " << *hi << "\n";
                auto p = prev(shi.lower_bound(perm[i]));
                // cout << "One before lower bound is " << *p << "\n";
                highest[i] = *p;
                shi.erase(p);
            }
            // cout << "Low is " << lowest[i] << " high is " << highest[i] << '\n';
        }
        vvvi[test][0] = lowest;
        vvvi[test][1] = highest;
    }
    for (auto&& vvi : vvvi) {
        for (auto&& vi : vvi) {
            for (auto num : vi) {
                cout << num << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
