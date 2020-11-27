#include <bits/stdc++.h>

using namespace std;

int64_t treeSize(int64_t node, unordered_map<int64_t, unordered_set<int64_t>>& g, unordered_set<int64_t>& cycle) {
    int64_t sz = 0;
    unordered_set<int64_t> visited;
    queue<int64_t> q;
    q.push(node);
    while (!q.empty()) {
        auto n = q.front();
        // cout << n << ',';
        q.pop();
        if (visited.count(n)) {
            continue;
        }
        visited.insert(n);
        ++sz;
        for (auto neighbor : g[n]) {
            if (cycle.count(neighbor) == 0) {
                q.push(neighbor);
            }
        }
    }
    return sz;
}

bool dfs(
        int64_t parent,
        int64_t child,
        unordered_map<int64_t, unordered_set<int64_t>>& g,
        unordered_set<int64_t>& seen,
        unordered_set<int64_t>& cycle,
        stack<int64_t>& s) {

    if (seen.count(child)) {
        cycle.insert(child);
        while (s.top() != child) {
            cycle.insert(s.top());
            s.pop();
        }
        return true;
    }
    s.push(child);
    seen.insert(child);
    for (auto node : g[child]) {
        if (node != parent && dfs(child, node, g, seen, cycle, s)) {
            return true;
        }
    }
    s.pop();
    return false;
}


unordered_set<int64_t> findCycle(unordered_map<int64_t, unordered_set<int64_t>>& g) {
    unordered_set<int64_t> cycle;
    unordered_set<int64_t> seen;
    stack<int64_t> s;
    auto firstNode = g.begin()->first;
    auto beforeDfs = chrono::system_clock::now();
    dfs(-1, firstNode, g, seen, cycle, s);
    auto afterDfs = chrono::system_clock::now();
    auto dur = afterDfs - beforeDfs;
    // cout << "Dfs duration: " << dur.count() << '\n';

    return cycle;
}
int64_t simplePaths(unordered_map<int64_t, unordered_set<int64_t>>& g) {
    // cout << "Simple paths\n";
    auto N = g.size();
    auto cycle = findCycle(g);
    // auto before = chrono::system_clock::now();
    auto cycleSize = cycle.size();
    auto simplePaths = N * (N - static_cast<int64_t>(1));
    for (auto node : cycle) {
        auto subtreeSize = treeSize(node, g, cycle);
        // cout << "Tree size at " << node << " is " << subtreeSize << '\n';
        simplePaths -= (subtreeSize * (subtreeSize - static_cast<int64_t>(1))) / static_cast<int64_t>(2);
    }
    // auto after = chrono::system_clock::now();
    // auto dur = after - before;
    // cout << "Rest duration: " << dur.count() << '\n';
    return simplePaths;
}


int main() {
    unordered_map<int64_t, unordered_set<int64_t>> graph;
    int64_t tests;
    cin >> tests;
    vector<int64_t> vi(tests);
    for (int64_t test = 0; test < tests; ++test) {
        graph.clear();
        int64_t edges;
        cin >> edges;
        for (int64_t edge = 0; edge < edges; ++edge) {
            int64_t src, dst;
            cin >> src >> dst;
            graph[src].insert(dst);
            graph[dst].insert(src);
        }
        vi[test] = simplePaths(graph);
    }
    for (auto num : vi) {
        cout << num << '\n';
    }
    return 0;
}
