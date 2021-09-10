#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[3];
int arr[2187][2187];  // 2187 = 3 ^ 7

void cut(int x, int y, int s) {
    if (s == 0) return;

    int flag = 0;
    for (int i = y; i < y + s; i++) {
        for (int j = x; j < x + s; j++) {
            if (arr[y][x] != arr[i][j]) {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 1) {
        for (int i = x; i < x + s; i += s / 3) {
            for (int j = y; j < y + s; j += s / 3) {
                cut(i, j, s / 3);
            }
        }
    } else {
        cnt[arr[y][x] + 1]++;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cut(0, 0, n);
    for (int i = 0; i < 3; i++) {
        cout << cnt[i] << '\n';
    }
}