#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
#define MAX_COST 1000000

int n;
int house[MAX][3];
int dp[MAX][3];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> house[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        dp[0][i] = house[0][0];
    }

    dp[1][0] = house[1][0] + min(house[0][1], house[0][2]);
    dp[1][1] = house[1][1] + min(house[0][0], house[0][2]);
    dp[1][2] = house[1][2] + min(house[0][0], house[0][1]);

    for (int i = 2; i < n; i++) {
        dp[i][0] = house[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = house[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = house[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    int result = dp[n-1][0];
    result = min(result, dp[n-1][1]);
    result = min(result, dp[n-1][2]);

    cout << result << '\n';
    
}

/*
3
26 40 83
49 60 57
13 89 99
*/