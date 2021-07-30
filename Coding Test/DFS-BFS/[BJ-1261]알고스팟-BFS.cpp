#include <bits/stdc++.h>
using namespace std;

#define INF 100000

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char miro[100][100];
bool v[100][100];

// BFS : 다익스트라

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> miro[i][j];
        }
    }

    v[0][0] = true;
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0,{0, 0}});
    int temp = INF;
    vector<int> result;
    while (!q.empty()) {
        int x = q.top().second.first;
        int y = q.top().second.second;
        int count = -q.top().first;
        q.pop();
        if (x == n - 1 && y == m - 1) {
            cout << count;
            return 0;
        }
        int temp = INF;
        for (int i = 0; i < 4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (!v[cy][cx] && 0 <= cx && cx <= n - 1 && 0 <= cy && cy <= m - 1) {
                v[cy][cx] = true;
                if (miro[cy][cx] == '1') q.push({-(count + 1), {cx,cy}});
                else if (miro[cy][cx] == '0') q.push({-count, {cx,cy}});
            }
        }
    }
}