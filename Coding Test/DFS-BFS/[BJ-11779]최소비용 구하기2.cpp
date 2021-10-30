#include <bits/stdc++.h>
using namespace std;

void Solution(int n, int m) {
    vector<pair<int, int>> graph[n + 1];
    for (int i = 0; i < m; i++) {
        int t1, t2, cost;
        cin >> t1 >> t2 >> cost;
        graph[t1].push_back({cost, t2});
    }

    int start, end;
    cin >> start >> end;

    int dist[n + 1];
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    vector<int> via[n + 1];
    via[start].push_back(start);

    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();

        if (curDist > dist[cur]) continue;
        for (auto i : graph[cur]) {
            int next = i.second;
            int nextDist = i.first;

            if (dist[next] > curDist + nextDist) {
                dist[next] = curDist + nextDist;
                pq.push({-dist[next], next});
                via[next] = via[cur];
                via[next].push_back(next);
            }
        }
    }
    
    cout << dist[end] << '\n';
    cout << via[end].size() << '\n';
    for(int i : via[end]) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    int n, m;
    cin >> n >> m;
    Solution(n, m);
}