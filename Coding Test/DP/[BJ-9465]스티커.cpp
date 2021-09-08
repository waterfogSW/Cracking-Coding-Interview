#include <bits/stdc++.h>
using namespace std;

int dp[2][100000], arr[2][100000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int t, n;

void init() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 100000; j++) {
            arr[i][j] = 0;
            dp[i][j] = 0;
        }
    }
}

int getDP() {
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];

    dp[0][1] = arr[0][1] + dp[1][0];
    dp[1][1] = arr[1][1] + dp[0][0];

    for (int i = 2; i < n; i++) {
        dp[0][i] = max(arr[0][i] + dp[1][i - 1], arr[0][i] + max(dp[1][i - 2], dp[0][i - 2]));
        dp[1][i] = max(arr[1][i] + dp[0][i - 1], arr[1][i] + max(dp[1][i - 2], dp[0][i - 2]));
    }

    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        init();
        cin >> n;

        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < n; k++) {
                cin >> arr[j][k];
            }
        }

        cout << getDP() << '\n';
    }
}
/*
1
5
50 10 100 20 40
30 50 70 10 60

1
7
10 30 10 50 100 20 40
20 40 30 50 60 20 80
*/