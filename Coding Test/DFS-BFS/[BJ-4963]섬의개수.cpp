#include <bits/stdc++.h>

using namespace std;

#define MAX 50

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int w, h;
bool _map[MAX][MAX];

bool _visit[MAX][MAX];
bool _visit_isl[MAX][MAX];

queue<pair<int, int>> q;
queue<pair<int, int>> isl_q;

vector<int> result;

void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            _map[i][j] = _visit[i][j] = _visit_isl[i][j] = false;
        }
    }
}

int main() {
    while (true) {
        cin >> w >> h;
        if (!w && !h) break;
        init();

        int count = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> _map[i][j];
            }
        }

        q.push({0, 0});
        _visit[0][0] = true;

        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();

            if (_map[cy][cx] && !_visit_isl[cy][cx]) {
                count++;
                isl_q.push({cx, cy});
                _visit_isl[cy][cx] = true;

                while (!isl_q.empty()) {
                    int isl_cx = isl_q.front().first;
                    int isl_cy = isl_q.front().second;
                    isl_q.pop();

                    for (int i = 0; i < 8; i++) {
                        int isl_nx = isl_cx + dx[i];
                        int isl_ny = isl_cy + dy[i];

                        if (isl_nx >= 0 && isl_nx < w && isl_ny >= 0 && isl_ny < h &&
                            !_visit_isl[isl_ny][isl_nx] && _map[isl_ny][isl_nx]) {
                            isl_q.push({isl_nx, isl_ny});
                            _visit_isl[isl_ny][isl_nx] = true;
                        }
                    }
                }
            }

            for (int i = 0; i < 8; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (nx >= 0 && nx < w && ny >= 0 && ny < h && !_visit[ny][nx]) {
                    q.push({nx, ny});
                    _visit[ny][nx] = true;
                }
            }
        }
        result.push_back(count);
    }

    for (int i : result) {
        cout << i << '\n';
    }
}