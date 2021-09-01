#include <bits/stdc++.h>
using namespace std;

int n, res;
int dp[100000];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dp[i];
    }

    res = dp[0];
    
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] > 0 && dp[i] + dp[i - 1] > 0) {
            dp[i] += dp[i - 1];
        }
        res = max(res, dp[i]);
    }

    cout << res;
}