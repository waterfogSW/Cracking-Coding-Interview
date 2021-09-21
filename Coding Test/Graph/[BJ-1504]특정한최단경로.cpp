#include <bits/stdc++.h>
using namespace std;

#define MAX 800 + 1

vector<pair<int, int>> graph[MAX];

int n, e;
int v1, v2;
int dist[MAX];

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

int checkSum(int a,int b, int c) {
    if(a == INT_MAX || b == INT_MAX || c == INT_MAX) return -1;
    return a + b + c;
}

int main() {
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int p1, p2, cost;
        cin >> p1 >> p2 >> cost;
        graph[p1].push_back({p2, cost});
        graph[p2].push_back({p1, cost});
    }
    cin >> v1 >> v2;

    auto fromStart = getCost(1);
    auto from_v1 = getCost(v1);
    auto from_v2 = getCost(v2);

    int temp1 = checkSum(fromStart[v1], from_v1[v2], from_v2[n]);
    int temp2 = checkSum(fromStart[v2], from_v2[v1], from_v1[n]);

    cout << min(temp1, temp2);
    return 0;
}