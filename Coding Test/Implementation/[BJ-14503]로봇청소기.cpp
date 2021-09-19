#include <bits/stdc++.h>
using namespace std;

int n, m;
int room[50][50];
int dx[4] = {-1, 0, 1, 0}; // 서, 북, 동, 남
int dy[4] = {0, -1, 0, 1};

bool isInside(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

int dfs(int x, int y, int d, int cnt) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dy[d];
        int ny = y + dx[d];
        d = (d + 3) % 4;

        if (isInside(nx, ny) && room[nx][ny] == 0) {
            room[nx][ny] = 2;
            return dfs(nx, ny, d, cnt + 1);
        }
    }

    int nd = (d + 3) % 4;  // 후진
    int nx = x + dy[nd];
    int ny = y + dx[nd];
    if (isInside(nx, ny) && room[nx][ny] != 1) return dfs(nx, ny, d, cnt);
    return cnt;
}

int main() {
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    room[r][c] = 2;
    cout << dfs(r, c, d, 1) << '\n';
}