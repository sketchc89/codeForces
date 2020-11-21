#include <bits/stdc++.h>

using namespace std;


int main() {
    int tests;
    cin >> tests;
    vector<int> vi(tests);

    for (int i = 0; i < tests; ++i) {
        int res = 0;
        int numBooks;
        cin >> numBooks;
        bool startBooks = false;
        int sizeGap = 0;
        for (int b = 0; b < numBooks; ++b) {
            int book;
            cin >> book;
            if (sizeGap && book) {
                res += sizeGap;
                sizeGap = 0;
            }
            if (book) {
                startBooks = true;
            } else if (startBooks) {
                ++sizeGap;
            }
        }
        vi[i] = res;
    }

    for (int num : vi) {
        cout << num << '\n';
    }
    return 0;
}
