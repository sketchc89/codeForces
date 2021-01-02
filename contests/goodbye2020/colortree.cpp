#include <bits/stdc++.h>
using namespace std;

int main() {
    // i/o

    int tests;
    cin >> tests;
    vector<vector<int64_t>> res(tests);

    for (int test = 0; test < tests; ++test) {
        int numNodes;
        cin >> numNodes;
        // map<int64_t, int, greater<int64_t>> weightNode;
        // unordered_map<int, map<int64_t, unordered_set<int>>> tree;
        // unordered_map<int, vector<pair<int, int>>>
        //         simpleTree;
        vector<pair<int64_t, int>> weights(numNodes);
        int64_t sum = 0;
        for (int i = 0; i < weights.size(); ++i) {
            int w;
            cin >> w;
            weights[i] = make_pair(w, i);
            sum += w;
        }
        sort(begin(weights), end(weights));
        stack<pair<int64_t, int>> w;
        for (int i = 0; i < weights.size(); ++i) {
            w.push(weights[i]);
        }
        unordered_map<int, int> counter;
        for (int i = 0; i < numNodes - 1; ++i) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            counter[a]++;
            counter[b]++;
        }
        res[test].push_back(sum);
        for (int i = 1; i < numNodes - 1; ++i) {
            auto weight = 0;
            auto node = -1;
            if (!w.empty()) {
                weight = w.top().first;
                node = w.top().second;
            }
            while (!w.empty() && counter[node] <= 1) {
                w.pop();
                weight = w.top().first;
                node = w.top().second;
            }
            sum += weight;
            counter[node]--;
            res[test].push_back(sum);
        }

        // for (int i = 0; i < numNodes - 1; ++i) {
        //     int a, b;
        //     cin >> a >> b;
        //     --a;
        //     --b;
        //     // tree[a][weights[b]].insert(b);
        //     // tree[b][weights[a]].insert(a);
        //     // simpleTree[a].push_back(b, weightVec[b]);
        //     // simpleTree[b].push_back(a, weightVec[a]);
        //     simpleTree[a].push_back({weightVec[b], b});
        //     simpleTree[b].push_back({weightVec[a], a});
        // }
        // for (int i = 0; i < numNodes - 1; ++i) {
        //     // sort(begin(simpleTree[a]), end(simpleTree[a]), [](auto&& lhs, auto&& rhs) { return lhs.second < rhs.second; });
        //     sort(begin(simpleTree[a]), end(simpleTree[a]));
        // }
        //
        // res[test].reserve(numNodes - 1);
        // int64_t sum = accumulate(begin(weights), end(weights), 0);
        // res[test].push_back(sum);  // 1 coloring
        // for (auto it = begin(simpleTree); it != end(simpleTree);) {
        //     if (it->second.size() == 1) {
        //         it = simpleTree.erase(it);
        //     } else {
        //         ++it;
        //     }
        // }
        // for (int coloring = 2; coloring < numNodes; ++coloring) {
        //     int64_t highestWeight = -1;
        //     int highestNode = -1;
        //     while (!weights.empty()) {
        //         if (simpleTree.count(highestNode)) {
        //             highestWeight = weights.top().first;
        //             highestNode = weights.top().second;
        //             break;
        //         } else {
        //             weight.pop();
        //         }
        //     }
        //
        //     sum += highestWeight;
        //
        //     int lowestNeighbor = simpleTree[highestNode][0].second;
        //     simpleTree[highestNode].erase(lowestNeighbor);
        //     if (simpleTree[highestNode].size() == 1) {
        //         simpleTree.erase(highestNode);
        //     }
        //
        //         for (int i = 0; node < weightVec.size(); ++i) {
        //             if (
        //
        //     if (tree[highestNode][highestWeight].size() == 0) {
        //             tree[highestNode].erase(highestWeight);
        //             if (tree[highestNode].size() == 0) {
        //                 tree.erase(highestNode);
        //             }
        // }
        // res[test].push_back(sum);
        // }
        // for (int coloring = 2; coloring < numNodes; ++coloring) {
        //     auto& highWeightMap = begin(tree)->second;
        //     int64_t highestWeight = begin(highWeightMap)->first;
        //     int highestNode = *begin(begin(highWeighMap)->second);
        //     sum += highestWeight;
        //
        //     tree[highestNode][highestWeight].erase(begin(tree[highestNode][highestWeight]));
        //     if (tree[highestNode][highestWeight].size() == 0) {
        //         tree[highestNode].erase(highestWeight);
        //         if (tree[highestNode].size() == 0) {
        //             tree.erase(highestNode);
        //         }
        //     }
        //     res[test].push_back(sum);
        // }
    }
    for (auto&& colorings : res) {
        for (auto num : colorings) {
            cout << num << ' ';
        }
        cout << '\n';
    }


    return EXIT_SUCCESS;
}
