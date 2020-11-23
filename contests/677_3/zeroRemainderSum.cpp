#include <bits/stdc++.h>

using namespace std;

constexpr int64_t N = 75;
constexpr int64_t BIG_MULT = 1000000000;  // INT32_MAX / 75
constexpr int64_t INF = 1000000;
array<array<array<array<int64_t, N>, N>, N>, N> dp;
void zeroRemainderSum(const vector<vector<int64_t>>& mat, const int64_t div) {
    int64_t R = mat.size();
    int64_t C = mat[0].size();
    int64_t MAX_PICK = C / 2;
    for (int64_t r = 0; r < R; ++r) {
        for (int64_t c = 0; c < C; ++c) {
            for (int64_t cnt = 0; cnt <= MAX_PICK; ++cnt) {
                for (int64_t rem = 0; rem < div; ++rem) {
                    dp[r][c][cnt][rem] = -INF;
                }
            }
        }
    }

    dp[0][0][0][0] = 0;
    for (int64_t row = 0; row < R; ++row) {
        /* loop up until the last column */
        for (int64_t col = 0; col < C - 1; ++col) {
            for (int64_t cnt = 0; cnt <= MAX_PICK; ++cnt) {
                for (int64_t rem = 0; rem < div; ++rem) {
                    if (dp[row][col][cnt][rem] == -INF) {
                        continue;
                    }
                    /* Don't take the element at row, col */
                    dp[row][col + 1][cnt][rem] =
                            max(dp[row][col + 1][cnt][rem],  //
                                dp[row][col][cnt][rem]);
                    if (cnt + 1 <= MAX_PICK) {
                        /* Take the element at row,col */
                        int64_t nextRem = (rem + mat[row][col]) % div;
                        dp[row][col + 1][cnt + 1][nextRem] =
                                max(dp[row][col + 1][cnt + 1][nextRem],  //
                                    dp[row][col][cnt][rem] + mat[row][col]);
                    }
                }
            }
        }

        /* handle last column */
        for (int64_t cnt = 0; cnt <= MAX_PICK; ++cnt) {
            for (int64_t rem = 0; rem < div; ++rem) {
                /* Don't take the element at row, col */
                dp[row + 1][0][0][rem] =
                        max(dp[row + 1][0][0][rem],  //
                            dp[row][C - 1][cnt][rem]);
                int64_t nextRem = (rem + mat[row][C - 1]) % div;
                if (cnt + 1 <= MAX_PICK) {
                    /* Take the element at row,col */
                    dp[row + 1][0][0][nextRem] =
                            max(dp[row][0][0][nextRem],  //
                                dp[row][C - 1][cnt][rem] + mat[row][C - 1]);
                }
            }
        }
    }
    int64_t maxSum = 0;
    for (int64_t cnt = 0; cnt <= MAX_PICK; ++cnt) {
        maxSum = max(maxSum, dp[R][0][cnt][0]);
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
