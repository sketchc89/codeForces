#include <bits/stdc++.h>
using namespace std;  // for cp only
constexpr static int INF = 1'000'000'000;

int path(int src, int dst, vector<unordered_map<int, int>>& graph) {
    int N = graph.size();
    vector<int> dist;
    dist.assign(N, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(make_pair(0, src));

    cerr << "Shortest path: " << src << ',' << dst << '\n';
    int nodeDist, node, weight, neighbor;
    while (!pq.empty()) {
        tie(nodeDist, node) = pq.top();
        pq.pop();
        if (nodeDist > dist[node]) {
            continue;
        }
        cerr << node << ',' << nodeDist << ',' << dist[node] << '\t';
        for (const auto& p : graph[node]) {
            tie(neighbor, weight) = p;
            if (nodeDist + weight < dist[neighbor]) {
                cout << "adding neighbor of " << node << "->" << neighbor << '\t';
                dist[neighbor] = nodeDist + weight;
                pq.emplace(make_pair(dist[neighbor], neighbor));
            }
        }
    }
    cout << "\nDistance: " << dist[dst] << '\n';
    return dist[dst];
}

int main() {
    int numDistricts, numRoads, numRoutes;
    cin >> numDistricts >> numRoads >> numRoutes;
    vector<unordered_map<int, int>> roads(numDistricts + 1);
    vector<pair<int, int>> edgeList(numRoads + 1);
    vector<pair<int, int>> routeList(numRoutes + 1);
    int src, dst, weight;

    for (int r = 1; r <= numRoads; ++r) {
        cin >> src >> dst >> weight;
        edgeList[r] = make_pair(src, dst);
        roads[src].emplace(make_pair(dst, weight));
        roads[dst].emplace(make_pair(src, weight));
    }
    vector<int> shortestPath(numRoutes + 1);
    for (int r = 1; r <= numRoutes; ++r) {
        cin >> src >> dst;
        routeList[r] = make_pair(src, dst);
    }
    shortestPath[0] = 0;  // ignore
    cerr << '\n';
    for (int r = 1; r <= numRoutes; ++r) {
        cerr << r << ',' << shortestPath.size() << ',';
        tie(src, dst) = routeList[r];
        shortestPath[r] = path(src, dst, roads);
    }
    int totalCost = accumulate(shortestPath.cbegin(), shortestPath.cend(), 0);
    int minTotalCost = totalCost;

    vector<int> newShortestPath(numRoutes + 1);
    newShortestPath[0] = 0;
    int freeStart, freeEnd;
    pair<int, int> res;
    for (int road = 1; road < numRoads; ++road) {
        tie(freeStart, freeEnd) = edgeList[road];
        int freeWeight = roads[freeStart][freeEnd];
        cout << "\nFree edge: " << freeStart << ',' << freeEnd << "-------\n";
        roads[freeStart][freeEnd] = 0;
        roads[freeEnd][freeStart] = 0;
        for (int route = 1; route <= numRoutes; ++route) {
            tie(src, dst) = routeList[route];
            int srcStart = path(src, freeStart, roads);
            int dstEnd = path(dst, freeEnd, roads);

            int srcEnd = path(src, freeEnd, roads);
            int dstStart = path(dst, freeStart, roads);
            newShortestPath[route] = min({shortestPath[route], srcStart + dstEnd, srcEnd + dstStart});
            cout << "-->Path " << src << ',' << dst << " now costs " << newShortestPath[route] << '\n';
        }
        int newTotalCost = accumulate(newShortestPath.cbegin(), newShortestPath.cend(), 0);
        if (newTotalCost < minTotalCost) {
            res = edgeList[road];
            minTotalCost = newTotalCost;
        }
        // undo making route free
        roads[freeStart][freeEnd] = freeWeight;
        roads[freeEnd][freeStart] = freeWeight;
    }

    cout << minTotalCost << '\n';
    return 0;
}
