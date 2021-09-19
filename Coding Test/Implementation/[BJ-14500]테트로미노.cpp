#include <bits/stdc++.h>
using namespace std;

int n, m;
int paper[500][500];

typedef vector<pair<int, int>> vp;

vector<vp> t;

void rotate(vp &tet) {
    vp tmp;
    for (int i = 0; i < 4; i++) {
        int tx = 4 - tet[i].second - 1;
        int ty = tet[i].first;
        tmp.push_back({tx, ty});
    }
    tet = tmp;
}

void horizon(vp &tet) {
    vp tmp;
    for (int i = 0; i < 4; i++) {
        int tx = tet[i].first;
        int ty = 4 - tet[i].second;
        tmp.push_back({tx, ty});
    }
    tet = tmp;
}

void init() {
    vp tmp(4, {0, 0});
    tmp = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
    t.push_back(tmp);
    rotate(tmp);
    t.push_back(tmp);

    tmp = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    t.push_back(tmp);

    tmp = {{0, 0}, {0, 1}, {0, 2}, {1, 2}};
    t.push_back(tmp);
    for (int i = 0; i < 3; i++) {
        rotate(tmp);
        t.push_back(tmp);
    }

    horizon(tmp);
    t.push_back(tmp);
    for (int i = 0; i < 3; i++) {
        rotate(tmp);
        t.push_back(tmp);
    }

    tmp = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
    t.push_back(tmp);
    rotate(tmp);
    t.push_back(tmp);
    horizon(tmp);
    t.push_back(tmp);
    rotate(tmp);
    t.push_back(tmp);

    tmp = {{0, 0}, {1, 0}, {2, 0}, {1, 1}};
    t.push_back(tmp);

    for(int i = 0; i < 3; i++) {
        rotate(tmp);
        t.push_back(tmp);
    }
}

bool isInside(int x, int y) {
    if (x >= m || x < 0 || y >= n || y < 0) return false;
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    init();
    int result = 0;

    for (int k = 0; k < t.size(); k++) {
        for (int y = -4; y < n; y++) {
            for (int x = -4; x < m; x++) {
                int sum = 0;
                for (int i = 0; i < 4; i++) {
                    int nx = x + t[k][i].first;
                    int ny = y + t[k][i].second;
                    if (!isInside(nx, ny)) {
                        sum = 0;
                        break;
                    } else {
                        sum += paper[ny][nx];
                    }
                }
                result = max(result, sum);
            }
        }
    }

    cout << result;
}