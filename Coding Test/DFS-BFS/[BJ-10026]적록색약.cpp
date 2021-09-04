#include <bits/stdc++.h>
using namespace std;

int n;
char rgb[100][100];
char rgb_cb[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int result[3];
int result_cb[3];
map<char, int> m = {{'R', 0}, {'G', 1}, {'B', 2}};

void bfs(int x, int y, char c) {
    result[m[c]]++;
    if (rgb[x][y] != 'X')
        rgb[x][y] = 'X';

    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            if (rgb[nx][ny] != c) continue;

            rgb[nx][ny] = 'X';
            q.push({nx, ny});
        }
    }
}

void bfs_cb(int x, int y, char c) {
    result_cb[m[c]]++;
    if (rgb_cb[x][y] != 'X')
        rgb_cb[x][y] = 'X';

    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            if (rgb_cb[nx][ny] != c) continue;

            rgb_cb[nx][ny] = 'X';
            q.push({nx, ny});
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rgb[i][j];
            rgb_cb[i][j] = rgb[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rgb_cb[i][j] == 'G') rgb_cb[i][j] = 'R';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char t = rgb[i][j];
            if (t != 'X') bfs(i, j, t);
        }
    }

    int c = result[0] + result[1] + result[2];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char t = rgb_cb[i][j];
            if (t != 'X') bfs_cb(i, j, t);
        }
    }

    int cb = result_cb[0] + result_cb[2];

    cout << c << ' ' << cb << '\n';

}