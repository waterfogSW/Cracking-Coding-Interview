#include <bits/stdc++.h>
using namespace std;

int n, k;
int dx[3] = {1, -1, 2};
int dist[100001];
int main() {
    cin >> n >> k;

    for (int i = 0; i < 100001; i++) {
        dist[i] = INT_MAX;
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, n});

    while (!pq.empty()) {
        int cs = -pq.top().first;
        int cx = pq.top().second;
        pq.pop();

        dist[cx] = min(dist[cx], cs);
        if (cx == k) continue;

        for (int i = 0; i < 3; i++) {
            int ns = cs;
            int nx = cx;

            if (i == 2) {
                nx *= dx[i];
            } else {
                nx += dx[i];
                ns += 1;
            }

            if (nx >= 0 && nx <= 100000) {
                if (dist[nx] > ns) pq.push({-ns, nx});
            }
        }
    }

    cout << dist[k] << '\n';
}