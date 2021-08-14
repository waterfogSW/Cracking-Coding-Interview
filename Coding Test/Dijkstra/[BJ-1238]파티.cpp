#include <bits/stdc++.h>
using namespace std;

#define MAX 1000 + 1

int n, m, x;
vector<pair<int, int>> graph[MAX];

vector<int> getCost(int start) {
    vector<int> dist(MAX);
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;

    pq.push({0, start});
    while (!pq.empty()) {
        int curPoint = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();

        if (dist[curPoint] < curDist) continue;
        for (auto i : graph[curPoint]) {
            int nextPoint = i.first;
            int nextDist = i.second;
            if (dist[nextPoint] > curDist + nextDist) {
                dist[nextPoint] = curDist + nextDist;
                pq.push({-dist[nextPoint], nextPoint});
            }
        }
    }
    return dist;
}

int main() {
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int p1, p2, cost;
        cin >> p1 >> p2 >> cost;
        graph[p1].push_back({p2, cost});
    }
    
    vector<int> result;
    auto back = getCost(x);
    for (int i = 1; i <= n; i++) {
        result.push_back(back[i] + getCost(i)[x]);
    }
    sort(result.begin(), result.end());

    cout << result.back();
}