#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solution(int n) {
    ll dp[101];
    dp[1] = 1;
    dp[2] = dp[1];
    dp[3] = dp[2];
    dp[4] = dp[3] + dp[1];
    dp[5] = dp[4];

    for(int i = 6; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-5]; 
    }
    return dp[n];
}

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << solution(n) << '\n';
    }

    return 0;
}