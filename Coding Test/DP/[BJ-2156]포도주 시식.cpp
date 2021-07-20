#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> grape;
int main() {

    cin >> n;
    int dp[n];
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        grape.push_back(temp);
    }

    if(n <= 2) {
        if(n == 1) cout << grape[0] << '\n';
        if(n == 2) cout << grape[0] + grape[1] << '\n';
        return 0;
    }


    dp[0] = grape[0];
    dp[1] = grape[0] + grape[1];
    
    int temp = max(grape[1] + grape[2], grape[0] + grape[2]);
    dp[2] = max(temp, dp[1]);

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(dp[i-2] + grape[i], dp[i-3] + grape[i-1] + grape[i]);
        dp[i] = max(dp[i-1], dp[i]);
    }

    cout << dp[n-1] << '\n';
}

/*

타겟 o:  

타겟 x: 

*/ 