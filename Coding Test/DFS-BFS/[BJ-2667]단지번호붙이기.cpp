#include <bits/stdc++.h>
using namespace std;

#define MAX 25

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
char apt_map[MAX][MAX];
bool _visit[MAX][MAX];
bool apt_visit[MAX][MAX];

vector<int> result;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> apt_map[i][j];
        }
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> apt_q;

    q.push({0, 0});
    _visit[0][0] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (apt_map[cy][cx] == '1' && !apt_visit[cy][cx]) {
            apt_q.push({cx, cy});
            apt_visit[cy][cx] = true;
            int cnt = 0;
            while (!apt_q.empty()) {
                int apt_cx = apt_q.front().first;
                int apt_cy = apt_q.front().second;

                apt_q.pop();
                cnt++;

                for (int i = 0; i < 4; i++) {
                    int apt_nx = apt_cx + dx[i];
                    int apt_ny = apt_cy + dy[i];

                    if (apt_nx >= 0 && apt_nx < n && apt_ny >= 0 &&
                        apt_ny < n && !apt_visit[apt_ny][apt_nx] &&
                        apt_map[apt_ny][apt_nx] == '1') {
                        apt_q.push({apt_nx, apt_ny});
                        apt_visit[apt_ny][apt_nx] = true;
                    }
                }
            }
            result.push_back(cnt);
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !_visit[ny][nx]) {
                q.push({nx, ny});
                _visit[ny][nx] = true;
            }
        }
    }

    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for (int i : result) {
        cout << i << '\n';
    }
}