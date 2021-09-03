#include <bits/stdc++.h>
using namespace std;

int n, m;
int tmt[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmt[i][j] == 0) return false;
        }
    }
    return true;
}

int main() {
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmt[i][j];
            if (tmt[i][j] == 1) {
                q1.push({j, i});
            }
        }
    }
    int cnt = 0;
    while (!q1.empty()) {
        while (!q1.empty()) {
            auto tmp = q1.front();
            q1.pop();
            q2.push(tmp);
        }

        while (!q2.empty()) {
            int cx = q2.front().first;
            int cy = q2.front().second;
            q2.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || tmt[ny][nx] != 0) continue;
                if (tmt[ny][nx] == 0) {
                    tmt[ny][nx] = 1;
                    q1.push({nx, ny});
                }
            }
        }
        cnt++;
    }

    if(!check()) cout << "-1";
    else cout << cnt - 1;
}