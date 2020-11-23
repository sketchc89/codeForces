#include <bits/stdc++.h>
using namespace std;  // for cp only
constexpr static int INF = 1'000'000'000;

void path(int src, vector<vector<int>>& dist, vector<unordered_map<int, int>>& graph) {
    dist[src][src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(make_pair(0, src));

    // cerr << "Shortest path: " << src << '\n';
    int nodeDist, node, weight, neighbor;
    while (!pq.empty()) {
        tie(nodeDist, node) = pq.top();
        pq.pop();
        if (nodeDist > dist[src][node]) {
            continue;
        }
        // cerr << node << ',' << nodeDist << ',' << dist[src][node] << '\t';
        for (const auto& p : graph[node]) {
            tie(neighbor, weight) = p;
            if (nodeDist + weight < dist[src][neighbor]) {
                // cerr << "adding neighbor of " << node << "->" << neighbor << ' ';
                dist[src][neighbor] = nodeDist + weight;
                pq.emplace(make_pair(dist[src][neighbor], neighbor));
            }
        }
    }
    // cerr << '\n';
}

int main() {
    int numDistricts, numRoads, numRoutes;
    cin >> numDistricts >> numRoads >> numRoutes;
    vector<unordered_map<int, int>> roads(numDistricts);
    vector<pair<int, int>> edgeList(numRoads);
    vector<pair<int, int>> routeList(numRoutes);
    int src, dst, weight;

    for (int r = 0; r < numRoads; ++r) {
        cin >> src >> dst >> weight;
        edgeList[r] = make_pair(src - 1, dst - 1);
        roads[src - 1].emplace(make_pair(dst - 1, weight));
        roads[dst - 1].emplace(make_pair(src - 1, weight));
    }
    vector<vector<int>> shortestPath(numDistricts, vector<int>(numDistricts, INF));
    for (int r = 0; r < numRoutes; ++r) {
        cin >> src >> dst;
        routeList[r] = make_pair(src - 1, dst - 1);
    }
    for (int district = 0; district < numDistricts; ++district) {
        path(district, shortestPath, roads);
    }
    int minTotalCost = INF;

    int freeStart, freeEnd;
    pair<int, int> res;
    for (int road = 0; road < numRoads; ++road) {
        int newTotalCost = 0;
        tie(freeStart, freeEnd) = edgeList[road];
        for (int route = 0; route < numRoutes; ++route) {
            tie(src, dst) = routeList[route];
            newTotalCost +=
                    min({shortestPath[src][freeStart] + shortestPath[freeEnd][dst],  //
                         shortestPath[src][freeEnd] + shortestPath[freeStart][dst],
                         shortestPath[src][dst]});
        }
        if (newTotalCost < minTotalCost) {
            res = edgeList[road];
            minTotalCost = newTotalCost;
        }
    }

    cout << minTotalCost << '\n';
    return 0;
}
