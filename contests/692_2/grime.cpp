/*
ID: sketchc89
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    // i/o

    string s;
    cin >> s;
    int64_t x, y;
    cin >> x >> y;
    // cout << "STRING: " << s << " XY " << x << ',' << y << '\t' << s.size() << '\n';
    vector<int64_t> numZeros(s.size() + 1, 0), numOnes(s.size() + 1, 0), numRZeros(s.size() + 1, 0), numROnes(s.size() + 1, 0);
    for (int i = 1; i <= s.size(); ++i) {
        if (s[i - 1] == '1') {
            numOnes[i] = numOnes[i - 1] + 1;
            numZeros[i] = numZeros[i - 1];
        } else if (s[i - 1] == '0') {
            numOnes[i] = numOnes[i - 1];
            numZeros[i] = numZeros[i - 1] + 1;
        } else {
            numOnes[i] = numOnes[i - 1];
            numZeros[i] = numZeros[i - 1];
        }
    }
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i + 1] == '1') {
            numROnes[i] = numROnes[i + 1] + 1;
            numRZeros[i] = numRZeros[i + 1];
        } else if (s[i + 1] == '0') {
            numROnes[i] = numROnes[i + 1];
            numRZeros[i] = numRZeros[i + 1] + 1;
        } else {
            numROnes[i] = numROnes[i + 1];
            numRZeros[i] = numRZeros[i + 1];
        }
    }
    // for (int i = 0; i <= s.size(); ++i) {
    //     cout << i << ':' << numOnes[i] << ',' << numZeros[i] << ',' << numROnes[i] << ',' << numRZeros[i] << '\n';
    // }

    int64_t score = 0;
    for (int i = 0; i < s.size(); ++i) {
        // cout << i << ':' << numROnes[i] << '\t' << numRZeros[i] << '\n';
        if (s[i] == '1') {
            // cout << "Position " << i << " has " << numRZeros[i] << " zeros ahead of it for a score of " << y * numRZeros[i] << "\n";
            score += y * numRZeros[i];
        } else if (s[i] == '0') {
            // cout << "Position " << i << " has " << numROnes[i] << " ones ahead of it for a score of " << x * numROnes[i] << "\n";
            score += x * numROnes[i];
        } else {
            int64_t scorePlaceOne = y * numRZeros[i] + x * numZeros[i];
            int64_t scorePlaceZero = x * numROnes[i] + y * numOnes[i];
            // cout << "Score of putting down zero " << scorePlaceZero << '\n';
            // cout << "Score of putting down one " << scorePlaceOne << '\n';
            if (scorePlaceZero > scorePlaceOne) {
                // cout << "Putting a 1 at position " << i << '\n';
                score += scorePlaceOne;
                // need a segtree i think
                for (int j = i; j <= s.size(); ++j) {
                    numOnes[j]++;
                }
                for (int j = i; j >= 0; --j) {
                    numROnes[j]++;
                }
            } else {
                // cout << "Putting a 0 at position " << i << '\n';
                score += scorePlaceZero;
                // need a segtree i think
                for (int j = i; j <= s.size(); ++j) {
                    numZeros[j]++;
                }
                for (int j = i; j >= 0; --j) {
                    numRZeros[j]++;
                }
            }
            //
        }
    }
    cout /*<< "Score: " */ << score << '\n';


    return EXIT_SUCCESS;
}
