#include <bits/stdc++.h>
using namespace std;

int n, r, c, cnt;

void dfs(int x, int y, int s) {
    if (x == c && y == r) {
        cout << cnt << '\n';
        return;
    }

    if (r < y + s && r >= y && c < x + s && c >= x) {
        dfs(x, y, s / 2);                  // 왼쪽 위
        dfs(x + s / 2, y, s / 2);          // 오른쪽 위
        dfs(x, y + s / 2, s / 2);          // 왼쪽 아래
        dfs(x + s / 2, y + s / 2, s / 2);  // 오른쪽 아래
    } else {
        cnt += s * s;
    }
}

int main() {
    cin >> n >> r >> c;
    dfs(0, 0, (1 << n));
}