#include <bits/stdc++.h>
using namespace std;

int n, m, result;

int lab[8][8];
int lab_temp[8][8];

bool v[8][8];
bool vv[8][8];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }
}

int check() {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 0) result++;
        }
    }
    return result;
}

int test() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            lab_temp[i][j] = lab[i][j];
        }
    }

    // 으아아아아
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 2) {
                v[i][j] = true;
                q.push({j, i});
            }
        }
    }

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        lab[cy][cx] = 2;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !v[ny][nx] &&
                lab[ny][nx] == 0) {
                    v[ny][nx] = true;
                    q.push({nx, ny});
            }
        }
    }

    int res = check();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = false;
            lab[i][j] = lab_temp[i][j];
        }
    }
    return res;
}

void dfs(int count) {
    if (count == 3) {
        result = max(result, test());
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 0) {
                lab[i][j] = 1;
                dfs(count + 1);
                lab[i][j] = 0;
            }
        }
    }
}

int main() {
    input();
    dfs(0);
    cout << result;
}