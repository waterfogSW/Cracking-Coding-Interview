#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000

int dp[101][10][1 << 10];

int Solution(int n) {
    int result = 0;
    int checkAll = (1 << 10) - 1;

    for (int i = 1; i < 10; i++) dp[1][i][1 << i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= checkAll; k++) {
                if (j == 0)
                    dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % MOD;
                else if (j == 9)
                    dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % MOD;
                else {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
                }
            }
        }
    }

    for (int i = 0; i < 10; i++) result = (result + dp[n][i][checkAll]) % MOD;

    return result;
}

int main() {
    int n;
    cin >> n;
    cout << Solution(n) << '\n';
}