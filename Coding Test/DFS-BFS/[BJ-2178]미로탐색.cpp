#include <bits/stdc++.h>
using namespace std;

int n, m;
int dist[100 + 2][100 + 2];
char miro[100 + 2][100 + 2];
bool _visit[100 + 2][100 + 2];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> miro[i][j];
        }
    }

    queue<pair<int, int>> q;
    _visit[1][1] = true;
    q.push({1, 1});
    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (!_visit[cy][cx] && miro[cy][cx] == '1') {
                dist[cy][cx] = dist[y][x] + 1;
                _visit[cy][cx] = true;
                q.push({cy, cx});
            }
        }
    }

    cout << dist[n][m] + 1 << '\n';
}