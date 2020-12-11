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

int spruce(vector<vector<int>>& mat) {
    int R = mat.size();
    int C = mat[0].size();
    int res = 0;
    vector<vector<int>> maxSpruce(R, vector<int>(C, 0));
    for (int row = R - 1; row >= 0; --row) {
        for (int col = C - 1; col >= 0; --col) {
            if (mat[row][col] == '.') {
                maxSpruce[row][col] = 0;
                continue;
            }
            if (row == R - 1 || col == 0 || col == C - 1) {
                maxSpruce[row][col] = 1;
                continue;
            }
            maxSpruce[row][col] = 1 + min(maxSpruce[row + 1][col - 1], min(maxSpruce[row + 1][col], maxSpruce[row + 1][col + 1]));
        }
    }
    for (int row = 0; row < R; ++row) {
        for (int col = 0; col < C; ++col) {
            res += maxSpruce[row][col];
        }
    }

    return res;
}
int main() {
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> mat(rows, vector<int>(cols, 0));
        for (int row = 0; row < rows; ++row) {
            string s;
            cin >> s;
            for (int col = 0; col < cols; ++col) {
                mat[row][col] = s[col];
            }
        }
        vi[test] = spruce(mat);
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
