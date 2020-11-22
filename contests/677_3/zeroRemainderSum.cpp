#include <bits/stdc++.h>

using namespace std;

void zeroRemainderSum(const vector<vector<int64_t>>& mat, const int div) {
    int R = mat.size();
    int C = mat[0].size();

    vector<vector<vector<vector<int64_t>>>> dp(
            R, vector<vector<vector<int64_t>>>(C, vector<vector<int64_t>>(C / 2, vector<int64_t>(div, -1e6))));

    dp[0][0][0][0] = 0;
    for (int row = 0; row < R; ++row) {
        for (int col = 1; col < C; ++col) {
            for (int cnt = 0; cnt < C / 2; ++cnt) {
                if (row != 0 && col == 0) {
                    dp[row][col][cnt];
                }
            }
        }
    }
    return max(0, 0);
    // last state transition//dp[R][0][0][0];
}

int main() {
    int row, col, div;
    cin >> row >> col >> div;
    vector<int> dp(col / 2, 0);
    vector<vector<int64_t>> mat(row, vector<int>(col, 0));
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            cin >> mat[r][c];
        }
        zeroRemainderSum(mat, div);
    }

    return 0;
}
