#include <bits/stdc++.h>
using namespace std;

int n, k;

int dp[101][100001];
vector<int> weight = {0};
vector<int> value = {0};

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int w, val;
        cin >> w >> val;
        weight.push_back(w);
        value.push_back(val);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][k];
}