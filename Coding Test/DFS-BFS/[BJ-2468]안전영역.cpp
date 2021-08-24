#include <bits/stdc++.h>
using namespace std;

int n, m;
int loc[100][100];
bool isSink[100][100];
bool v[100][100];
bool nsv[100][100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> loc[i][j];
            m = max(m, loc[i][j]);
        }
    }
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            isSink[i][j] = false;
            v[i][j] = false;
            nsv[i][j] = false;
        }
    }
}

void checkSink(int height) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (loc[i][j] <= height) isSink[i][j] = true;
        }
    }
}

int bfs() {
    int result = 0;

    queue<pair<int, int>> q;
    queue<pair<int, int>> sq;

    v[0][0] = true;
    q.push({0, 0});

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (!isSink[cy][cx] && !nsv[cy][cx]) {
            result++;

            nsv[cy][cx] = true;
            sq.push({cx, cy});

            while (!sq.empty()) {
                int ccx = sq.front().first;
                int ccy = sq.front().second;
                sq.pop();

                for (int i = 0; i < 4; i++) {
                    int nnx = ccx + dx[i];
                    int nny = ccy + dy[i];

                    if (nnx >= 0 && nnx < n && nny >= 0 && nny < n &&
                        !isSink[nny][nnx] && !nsv[nny][nnx]) {
                        nsv[nny][nnx] = true;
                        sq.push({nnx, nny});
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !v[ny][nx]) {
                v[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }

    return result;
}

int main() {
    input();
    int result = 1;

    for (int i = 0; i < m; i++) {
        init();
        checkSink(i);
        result = max(bfs(), result);
    }
    cout << result;
}
