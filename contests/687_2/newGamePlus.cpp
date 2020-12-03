#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t bosses, resets;
    cin >> bosses >> resets;
    vector<int64_t> b(bosses);
    for (int64_t i = 0; i < b.size(); ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end(), greater<int64_t>());
    int64_t score = 0;
    int64_t bossScore = 0;
    for (int i = 0; i < bosses; ++i) {
        score += bossScore;
        if (i == bosses - 1) {
            break;
        }
        bossScore += b[i];
        if (bossScore < 0 && bosses - i < resets) {
            break;
        }
        if (bossScore < 0 && resets > 0) {
            while (bossScore < 0 && resets > 0) {
                --bosses;
                --resets;
            }
            if (i < bosses - 1) {
                score += bossScore;
            }
            bossScore = 0;
        }
    }
    cout << score << '\n';
    return 0;
}
