#include<bits/stdc++.h>
using namespace std;

int t;
int dp[10+1];

vector<int> ans;
int main() {
    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    for (int i = 0; i < t; i++) {
        int temp;
        cin >> temp;
        ans.push_back(dp[temp]);
    }
    for (auto i : ans) {
        cout << i << '\n';
    }
    
}