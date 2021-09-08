#include <bits/stdc++.h>
using namespace std;

int n, m, result;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char mp[1000][1000];
bool v[1000][1000];

typedef priority_queue<pair<int, pair<int, int>>> prq;
prq pq, ppq;

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = false;
        }
    }
}

void bfs() {
    while (!pq.empty()) {
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        int dist = -pq.top().first;
        pq.pop();

        if (dist > result) return;

        if (cx == m - 1 && cy == n - 1)
            result = min(result, dist);

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || v[ny][nx]) continue;
            if (mp[ny][nx] == '1') {
                v[ny][nx] = 1;
                ppq.push({-(dist + 1), {nx, ny}});
                continue;
            }

            v[ny][nx] = 1;
            pq.push({-(dist + 1), {nx, ny}});
        }
    }
}

void wall_bfs() {
    while (!ppq.empty()) {
        int cx = ppq.top().second.first;
        int cy = ppq.top().second.second;
        int dist = -ppq.top().first;
        ppq.pop();

        if (dist > result) return;

        if (cx == m - 1 && cy == n - 1)
            result = min(result, dist);

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1) continue;
            if (v[ny][nx] || mp[ny][nx] == '1') continue;

            v[ny][nx] = 1;
            ppq.push({-(dist + 1), {nx, ny}});
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }

    result = INT_MAX;
    v[0][0] = 1;
    pq.push({-1, {0, 0}});

    bfs();
    init();
    wall_bfs();

    if (result == INT_MAX)
        cout << "-1" << '\n';
    else
        cout << result << '\n';
}

/*
8 8
01000100
01010100
01010100
01010100
01010100
01010100
01010100
00010100

5 10
0000011000
1101011010
0000000010
1111111110
1111000000

6 4
0000
1110
0110
0000
0111
0000
*/