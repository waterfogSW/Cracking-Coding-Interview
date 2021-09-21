#include <bits/stdc++.h>
using namespace std;

#define INF 3000000
#define MAX 20010

int dist[MAX];
int v, e, start;
vector<pair<int, int>> graph[MAX];
int main() {
    cin >> v >> e >> start;

    for (int i = 1; i <= v; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    for (int i = 0; i < e; i++) {
        int tmp1, tmp2, cost;
        cin >> tmp1 >> tmp2 >> cost;
        graph[tmp1].push_back({tmp2, cost});
    }
    // priority queue에서 pair는 첫번째 원소 먼저 정렬후 두번째 원소 정렬
    // 시간차이가 많이 나므로 우선적으로 정렬해야하는것 부터 진행
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        // 다음 인덱스 결정
        if (dist[current] < distance) continue;
        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i].first;
            int nextDist = graph[current][i].second;
            if(dist[next] > distance + nextDist) {
                dist[next] = distance + nextDist;
                pq.push({-dist[next], next});
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}