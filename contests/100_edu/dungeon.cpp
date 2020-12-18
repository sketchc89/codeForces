/*
ID: sketchc1
LANG: C++14
TASK: milk
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    // i/o
    int t, a, b, c;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        cin >> a >> b >> c;
        if ((a + b + c) % 9 == 0 && a >= (a + b + c) / 9 && b >= (a + b + c) / 9 && c >= (a + b + c) / 9) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


    return EXIT_SUCCESS;
}

// 3 + 2 + 4 = 6 + 3
// 6 + 4 + 8 = 5 + 3 + 7 = 15 + 3
