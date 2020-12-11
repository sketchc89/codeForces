#include <bits/stdc++.h>

using namespace std;

// int count(int row, int col, vector<vector<int>>& mat) {
//     int R = mat.size();
//     int C = mat[0].size();
//     queue<pair<pair<int, int>, int>> q;
//     int max_depth = 0;
//     q.emplace(make_pair(make_pair(row, col), 1));
//     while (!q.empty()) {
//         auto r = q.front().first.first;
//         auto c = q.front().first.second;
//         auto d = q.front().second;
//         q.pop();
//         max_depth = max(max_depth, d - 1);
//         if (r >= R || c < 0 || c >= C || mat[r][c] == '.') {
//             break;
//         }
//         for (int i = c; i < c + 2 * d - 1; ++i) {
//             if (mat[r][i] != '*') {
//                 return max_depth;
//             }
//         }
//         q.emplace(make_pair(make_pair(r + 1, c - 1), d + 1));
//         // q.emplace(make_pair(make_pair(r + 1, c), d + 1));
//         // q.emplace(make_pair(make_pair(r + 1, c + 1), d + 1));
//     }
//     return max_depth;
// }

int main() {
    int64_t tests;
    cin >> tests;
    vector<string> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int n, k;

        cin >> n >> k;
        string s = "";
        for (int i = 0; i < n; ++i) {
            if (i % 3 == 0) {
                s.push_back('a');
            } else if (i % 3 == 1) {
                s.push_back('b');
            } else {
                s.push_back('c');
            }
            vi[test] = s;
        }
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
