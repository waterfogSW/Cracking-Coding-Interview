#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int min(int x, int y) {
    return x < y ? x : y;
}

int Find(int a, int *root) {
    if (root[a] == a)
        return a;
    else
        return root[a] = Find(root[a], root);  // 재귀 감소
}

void Union(int x, int y, int *root) {
    x = Find(x, root);
    y = Find(y, root);
    x > y ? root[y] = x : root[x] = y;
}

bool isInside(int x, int y, int n, int m) {
    if (x >= n || x < 0 || y >= m || y < 0) return false;
    return true;
}

void travIsland(int x, int y, int n, int m, vector<vector<int>> &map, vector<vector<bool>> &visit, int idx) {
    queue<pair<int, int>> q;

    q.push({x, y});
    visit[x][y] = 1;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        map[cx][cy] = idx;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!isInside(nx, ny, n, m)) continue;
            if (map[nx][ny] == 1 && !visit[nx][ny]) {
                q.push({nx, ny});
                visit[nx][ny] = 1;
            }
        }
    }
}

int Solution(int n, int m, vector<vector<int>> &map) {
    vector<vector<bool>> visit(n, vector<bool>(m, 0));
    int idx = 1;  // 섬의 개수
    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && map[i][j] == 1) {
                travIsland(i, j, n, m, map, visit, idx);
                idx++;
            }
        }
    }

    int minDist[idx + 1][idx + 1];
    for (int i = 1; i <= idx; i++) {
        for (int j = 1; j < idx; j++) {
            minDist[i][j] = 100;
        }
    }

    // 각 섬에서 다음섬까지 일직선으로 잰 거리중 1이 아닌 최솟값.
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (map[x][y] == 0) continue;

            int isl1 = map[x][y], isl2 = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i], dist = 1;
                if (!isInside(nx, ny, n, m) || map[nx][ny] == isl1) continue;
                while (isInside(nx, ny, n, m)) {
                    if (map[nx][ny] != 0) {
                        int isl2 = map[nx][ny];
                        if (dist > 2) {
                            minDist[isl1][isl2] = min(minDist[isl1][isl2], dist - 1);
                            minDist[isl2][isl1] = min(minDist[isl2][isl1], dist - 1);
                        }
                        break;
                    }
                    dist += 1;
                    nx += dx[i];
                    ny += dy[i];
                }
            }
        }
    }

    priority_queue<tuple<int, int, int>> pq;

    int *root = new int[idx];
    for (int i = 1; i < idx; i++) root[i] = i;

    for (int i = 1; i < idx; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j || minDist[i][j] == 100) continue;
            pq.push({-minDist[i][j], i, j});
        }
    }

    while (!pq.empty()) {
        int w = -get<0>(pq.top());
        int v1 = get<1>(pq.top());
        int v2 = get<2>(pq.top());
        pq.pop();
        // cout << w << ' ' << v1 << ' ' << v2 << '\n';
        if (Find(v1, root) != Find(v2, root)) {
            Union(v1, v2, root);
            result += w;
        }
    }

    // for (int i = 1; i < idx; i++) {
    //     for (int j = 1; j < idx; j++) {
    //         cout << minDist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // for(int i = 1; i < idx; i++) {
    //     cout << root[i] << ' ';
    // }
    // if(result == 0) return -1;
    int temp = Find(1,root);
    for(int i = 2; i < idx; i++) {
        if(temp != Find(i,root)) return -1;
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n + 10, vector<int>(m + 10, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    cout << Solution(n, m, map) << '\n';
}