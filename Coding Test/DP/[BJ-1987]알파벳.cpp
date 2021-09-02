#include <bits/stdc++.h>
using namespace std;

int r, c;

char board[21][21];
bool v[26];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int result;

void dfs(int x, int y, int res) {

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > c || ny < 1 || ny > r) continue;
        if (v[board[ny][nx] - 65]) {
            result = max(result, res);
            continue;
        }

        v[board[ny][nx] - 65] = 1;
        dfs(nx, ny, res + 1);
        v[board[ny][nx] - 65] = 0;
    }
}

int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> board[i][j];
        }
    }
    v[board[1][1] - 65] = true;
    dfs(1, 1, 1);
    cout << result << '\n';
}