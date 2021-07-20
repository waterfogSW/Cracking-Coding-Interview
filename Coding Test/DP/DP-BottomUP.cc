#include <bits/stdc++.h>
using namespace std;


int n;
int dp[1000000+1];

int main(){
    cin >> n;

    for(int i=2; i<=n; i++){ // 증가
        
        // 1로 뺴기 (어떤 숫자도 가능)
        dp[i] = dp[i-1] + 1;
        // dp[2] = dp[1] + 1 = 1

        // 조건에 따라
        if(i%2 == 0)
            dp[i] = min(dp[i/2]+1, dp[i]);
        if(i%3 == 0)
            dp[i] = min(dp[i/3]+1, dp[i]);

    }

    cout << dp[n] << '\n';

}