#include <bits/stdc++.h>

using namespace std;

constexpr int64_t N = 75;
constexpr int64_t BIG_MULT = 1000000000;  // INT32_MAX / 75
array<array<array<array<int64_t, N>, N>, N>, N> dp;
void zeroRemainderSum(const vector<vector<int64_t>>& mat, const int64_t div) {
    int64_t R = mat.size();
    int64_t C = mat[0].size();
    for (int64_t r = 0; r < R; ++r) {
        for (int64_t c = 0; c < C; ++c) {
            for (int64_t cnt = 0; cnt <= C / 2; ++cnt) {
                for (int64_t rem = 0; rem < div; ++rem) {
                    dp[r][c][cnt][rem] = -1000000;
                }
            }
        }
    }

    dp[0][0][0][0] = 0;
    dp[0][0][1][1] = mat[0][0];
    for (int64_t row = 0; row < R; ++row) {
        if (row > 0) {
            // first column is maximum of the previous row end
            for (int64_t cnt = 0; cnt <= C / 2 + 1; ++cnt) {
                for (int64_t rem = 0; rem < div; ++rem) {
                    if (cnt <= C / 2) {
                        dp[row][0][0][rem] =
                                max(dp[row][0][0][rem],  //
                                    dp[row - 1][C - 1][cnt][rem]);
                    }
                    int64_t prevRem = (BIG_MULT * div + rem - mat[row][0] % div) % div;
                    if (cnt > 0) {
                        dp[row][0][0][rem] =
                                max(dp[row][0][0][rem],  //
                                    dp[row - 1][C - 1][cnt - 1][prevRem] + mat[row][0]);
                    }
                }
            }
        }
        for (int64_t col = 1; col < C; ++col) {
            for (int64_t cnt = 0; cnt <= C / 2; ++cnt) {
                for (int64_t rem = 0; rem < div; ++rem) {
                    /* Don't take the element at row, col */
                    dp[row][col][cnt][rem] =
                            max(dp[row][col][cnt][rem],  //
                                dp[row][col - 1][cnt][rem]);
                    int64_t prevRem = (BIG_MULT * div + rem - mat[row][col] % div) % div;
                    if (cnt > 0) {
                        /* Take the element at row,col */
                        dp[row][col][cnt][rem] =
                                max(dp[row][col][cnt][rem],  //
                                    dp[row][col - 1][cnt - 1][prevRem] + mat[row][col]);
                    }
                }
            }
        }
    }
    int64_t maxSum = 0;
    for (int64_t cnt = 0; cnt <= C / 2; ++cnt) {
        maxSum = max(maxSum, dp[R - 1][C - 1][cnt][0]);
    }
    cout << maxSum << '\n';
}

int main() {
    int64_t row, col, div;
    cin >> row >> col >> div;
    vector<int64_t> dp(col / 2, 0);
    vector<vector<int64_t>> mat(row, vector<int64_t>(col, 0));
    for (int64_t r = 0; r < row; ++r) {
        for (int64_t c = 0; c < col; ++c) {
            cin >> mat[r][c];
        }
    }
    zeroRemainderSum(mat, div);

    return 0;
}
