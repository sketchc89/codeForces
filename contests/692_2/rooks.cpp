/*
ID: sketchc89
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            _size.push_back(1);
            _parent.push_back(i);
        }
    }

    int root(int x) {
        while (x != _parent[x]) {
            _parent[x] = _parent[_parent[x]];
            x = _parent[x];
        }
        return x;
    }

    bool find(int x, int y) {
        return root(x) == root(y);
    }

    void unify(int x, int y) {
        if (find(x, y)) {
            return;
        }

        x = root(x);
        y = root(y);
        if (_size[x] < _size[y]) {
            swap(x, y);
        }
        _size[x] += _size[y];
        _parent[y] = x;
    }

    int size(int x) {
        return _size[root(x)];
    }

private:
    vector<int> _parent, _size;
};


int main() {
    // i/o

    int tests;
    cin >> tests;

    vector<int> res(tests);
    for (int test = 0; test < tests; ++test) {
        // cout << "Test " << test << '\n' << string(10, '-') << '\n';
        int boardSize, numRooks;
        cin >> boardSize >> numRooks;

        vector<pair<int, int>> rooks(numRooks);
        vector<pair<int, int>> threatened(boardSize, {-1, -1});
        UnionFind uf(numRooks);
        for (int r = 0; r < numRooks; ++r) {
            cin >> rooks[r].first >> rooks[r].second;
            rooks[r].first--;
            rooks[r].second--;
            if (threatened[rooks[r].first].first == -1) {
                threatened[rooks[r].first].first = r;
            } else {
                threatened[rooks[r].first].second = r;
            }
            if (threatened[rooks[r].second].first == -1) {
                threatened[rooks[r].second].first = r;
            } else {
                threatened[rooks[r].second].second = r;
            }
        }

        // for (int i = 0; i < threatened.size(); ++i) {
        //     cout << "Row: " << i << " is ";
        //     if (threatened[i].first == -1) {
        //         cout << "not threatened\n";
        //     } else {
        //         cout << "threatened by rook# " << threatened[i].first << " at position " << rooks[threatened[i].first].first << ',';
        //         rooks[threatened[i].first].second;
        //         if (threatened[i].second == -1) {
        //             cout << '\n';
        //         } else {
        //             cout << " and rook# " << threatened[i].second << " at position " << rooks[threatened[i].second].first << ','
        //                  << rooks[threatened[i].second].second << '\n';
        //         }
        //     }
        // }

        for (int i = 0; i < threatened.size(); ++i) {
            if (threatened[i].second == -1) {
                continue;
            } else {
                // cout << "Rook " << threatened[i].first << " and " << threatened[i].second << " are threatening same diag\n";
                uf.unify(threatened[i].first, threatened[i].second);
            }
        }

        vector<unordered_set<int>> v(numRooks);
        for (int r = 0; r < numRooks; ++r) {
            // cout << "Root of " << r << " is " << uf.root(r) << '\n';
            v[uf.root(r)].insert(rooks[r].first);
            v[uf.root(r)].insert(rooks[r].second);
        }
        int moves = 0;
        for (int r = 0; r < numRooks; ++r) {
            if (v[r].size() <= 1) {
                continue;  // either on diagonal or not the parent of component
            }
            // cout << "Rook: " << r << ';';
            // for (auto i : v[r]) {
            //     cout << i << ',';
            // }
            // cout << "Size of component with root " << r << " is " << uf.size(r) << '\n';
            if (v[r].size() == uf.size(r)) {
                moves += uf.size(r) + 1;
            } else {
                moves += uf.size(r);
            }
        }
        res[test] = moves;
    }


    for (auto&& n : res) {
        cout << n << '\n';
    }


    return EXIT_SUCCESS;
}
