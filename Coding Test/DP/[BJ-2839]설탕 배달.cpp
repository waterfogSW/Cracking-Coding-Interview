#include <bits/stdc++.h>
using namespace std;

int weight;

int main() {
    cin >> weight;
    int dp[weight+1];
    
    // 한계조건
    if(weight == 3) {
        cout << "1";
        return 0;
    }
    else if(weight < 5) {
        cout << "-1";
        return 0;
    }

    // dp
    dp[0] = 0;
    dp[1] = 9999;
    dp[2] = 9999;
    dp[3] = 1;
    dp[4] = 9999;
    dp[5] = 1;

    for (int i = 5; i <= weight; i++) {
        dp[i] = min(dp[i-3] + dp[3], dp[i-5] + dp[5]);
    }
    if(dp[weight] > 5000){
        cout << "-1";
        return 0;
    }
    cout << dp[weight];
}