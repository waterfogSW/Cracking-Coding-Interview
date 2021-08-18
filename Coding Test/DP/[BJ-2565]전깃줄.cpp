#include <bits/stdc++.h>
using namespace std;

int n, result;
vector<pair<int, int>> line;
int dp[100 + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        line.push_back({tmp1, tmp2});
    }

    sort(line.begin(), line.end());

    for (int k = 0; k < n; k++) {
        dp[k] = 1;
        for (int i = 0; i < k; i++) {
            if(line[i].second < line[k].second)
                dp[k] = max(dp[k], dp[i] + 1);
        }
        result = max(result, dp[k]);
    }

    cout << n - result;
}