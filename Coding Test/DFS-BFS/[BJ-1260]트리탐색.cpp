#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int n, m, v;
bool graph[MAX][MAX];
bool dfs_visit[MAX];
bool bfs_visit[MAX];

void dfs(int next) {
    dfs_visit[next] = true;
    cout << next << ' ';
    for (int i = 1; i <= n; i++) {
        if (dfs_visit[i] == false && graph[next][i] == true)
            dfs(i);
    }
}

void bfs(int next) {
    queue<int> q;
    q.push(next);
    bfs_visit[next] = true;
    while (!q.empty()) {
        next = q.front();
        q.pop();
        cout << next << ' ';
        for (int i = 1; i <= n; i++) {
            if (bfs_visit[i] == false && graph[next][i] == true) {
                q.push(i);
                bfs_visit[i] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = true;
    }
    dfs(v);
    cout << '\n';
    bfs(v);
    cout << '\n';
}