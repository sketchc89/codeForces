#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t tests, n;
    cin >> tests;
    vector<vector<int64_t>> vi(tests, vector<int64_t>(10, 0));
    for (int i = 0; i < vi.size(); ++i) {
        cin >> n;
        vector<vector<pair<int64_t, int64_t>>> digits(10);
        string row;
        for (int r = 0; r < n; ++r) {
            cin >> row;
            for (int c = 0; c < n; ++c) {
                digits[row[c] - '0'].push_back(make_pair(r, c));
            }
        }
        int dig = 0;
        for (auto&& d : digits) {
            int64_t maxTri = 0;
            // cout << "Start " << dig << '\n';
            for (int j = 0; j < d.size(); ++j) {
                const auto& p1 = d[j];
                for (int k = j + 1; k < d.size(); ++k) {
                    const auto& p2 = d[k];
                    auto maxH = max(p1.first, max(p2.first, max(n - 1 - p1.first, n - 1 - p2.first)));
                    auto maxV = max(p1.second, max(p2.second, max(n - 1 - p1.second, n - 1 - p2.second)));

                    // cout << p1.first << ',' << p1.second << '\t';
                    // cout << p2.first << ',' << p2.second << '\n';
                    if (p1.first == p2.first) {
                        maxTri = max(maxTri, abs(p2.second - p1.second) * maxH);
                        // cout << "Tri1: " << area << '\t' << abs(p2.first - p1.first) << '\t' << p1.second << '\n';
                    } else if (p1.second == p2.second) {
                        maxTri = max(maxTri, abs(p2.first - p1.first) * maxV);
                        // cout << "Tri2: " << area << '\n';
                    } else {
                        maxTri = max(maxTri, abs(p2.first - p1.first) * maxV);
                        maxTri = max(maxTri, abs(p2.second - p1.second) * maxH);
                    }
                    if (maxTri == n * n) {
                        break;
                    }
                }
                // cout << '\n';
            }
            // cout << dig << '\t' << maxTri << '\n';
            vi[i][dig] = maxTri;
            ++dig;
        }
    }
    for (auto&& v : vi) {
        for (auto n : v) {
            cout << n << ' ';
        }
        cout << '\n';
    }
    return 0;
}
