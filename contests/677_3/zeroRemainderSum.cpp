#include <bits/stdc++.h>

using namespace std;

int main() {
    int row, col, div;
    cin >> row >> col >> div;
    vector<int> dp(col / 2, 0);
    vector<vector<int64_t>> mat(row, vector<int>(col, 0));
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            cin >> mat[r][c];
        }
        sort(row.begin(), row.end(), greater<int64_t>());
    }

    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
