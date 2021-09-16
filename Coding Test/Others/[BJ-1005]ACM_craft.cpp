#include <bits/stdc++.h>
using namespace std;

#define BUILD 1001

int solution() {
    int n, k, w;
    int result = 0;

    cin >> n >> k;

    int time[n + 1] = {0};
    int dist[n + 1] = {0};
    int inDegree[n + 1] = {0};  // 진입 차수

    vector<int> order[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> time[i];
    }

    for (int i = 0; i < k; i++) {
        int b1, b2;
        cin >> b1 >> b2;

        order[b1].push_back(b2);
        inDegree[b2]++;
    }
    cin >> w;

    queue<int> q;
    // 진입 차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // 
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        int cost = 0;
        for (int next : order[x]) {
            dist[next] = max(dist[next], dist[x] + time[x]);
            if(--inDegree[next] == 0) q.push(next);
        }
    }

    return dist[w] + time[w];
}

int main() {
    int t;
    vector<int> result;
    cin >> t;

    for (int i = 0; i < t; i++) {
        result.push_back(solution());
    }
    for (int i : result) {
        cout << i << '\n';
    }
}