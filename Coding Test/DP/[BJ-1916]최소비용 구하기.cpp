#include <bits/stdc++.h>
using namespace std;

#define MAX 1001  //도시의 최대개수
#define INF (100000 * 1000)
int dist[MAX];
int n, m, start, dest;
vector<pair<int, int>> bus[MAX];
priority_queue<pair<int, int>> pq;
int main() {
    // 데이터 입력
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s_tmp, d_tmp, _cost;
        cin >> s_tmp >> d_tmp >> _cost;
        bus[s_tmp].push_back({_cost, d_tmp});
    }

    cin >> start >> dest;

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (dist[current] < distance) continue;
        for (int i = 0; i < bus[current].size(); i++) {
            int next = bus[current][i].second;
            int nextDist = bus[current][i].first;
            if (dist[next] > distance + nextDist) {
                dist[next] = distance + nextDist;
                pq.push({-dist[next], next});
            }
        }
    }

    if(dist[dest] == INF) cout << "INF" << '\n';
    else cout << dist[dest] << '\n';
    
}