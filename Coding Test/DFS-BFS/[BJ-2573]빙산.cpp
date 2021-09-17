#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool checkAllMelted(int n, int m, vector<vector<int>> &ice) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(ice[i][j] > 0) return false;
        }
    }
    return true;
}

void dfs(int n, int m, int x, int y, vector<vector<bool>> &visit, vector<vector<int>> &ice) {
    visit[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1) continue;
        if (visit[ny][nx] || ice[ny][nx] == 0) continue;

        dfs(n, m, nx, ny, visit, ice);
    }
}

int piece(int n, int m, vector<vector<int>> &ice) {
    int result = 0;

    vector<vector<bool>> visit(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ice[i][j] > 0 && !visit[i][j]) {
                dfs(n, m, j, i, visit, ice);
                result++;
            }
        }
    }

    return result;
}

void melt(int n, int m, vector<vector<int>> &ice) {
    auto tmp = ice;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ice[i][j] == 0) continue;
            q.push({j, i});
        }
    }

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (tmp[ny][nx] == 0 && ice[cy][cx] > 0) {
                ice[cy][cx]--;
            }
        }
    }
}

int solution(int n, int m, vector<vector<int>> &ice) {
    int year = 0;
    while (piece(n, m, ice) < 2) {
        if(checkAllMelted(n, m, ice)) return 0;
        melt(n, m, ice);
        year++;
    }

    return year;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ice(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ice[i][j];
        }
    }

    cout << solution(n, m, ice) << '\n';
}