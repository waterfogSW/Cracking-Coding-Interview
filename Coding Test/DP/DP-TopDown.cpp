    // vector<int> dp(n+1);
    // dp[n] = 0;
    // fill(dp.begin(), dp.end() - 1, MAX);
    // for (int i = n; i > 1; i--) {
    //     dp[i-1] = min(dp[i] + 1, dp[i-1]);
    //     if(i % 3 == 0) {
    //         dp[i/3] = min(dp[i] + 1, dp[i/3]);
    //     }
    //     if (i % 2 == 0) {
    //         dp[i/2] = min(dp[i] + 1, dp[i/2]);
    //     }
    // }
    // cout << dp[1] << '\n';
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

/*
재귀 => 시간 초가 => dp 붙이고 다이내믹으로
=> 바텀업 반복문  / 내 경험상 탑다운(재귀+dp)보다 바텀업(반복)이 조금 빨랐음. 
*/

// 피보나치 상기, 무언가를 메모하면 좋겠다! 
// 메모제이션 <- 보통 전역으로 선언, 자동으로 0 초기화
int dp[1000000+1];

int dfs(int n){
    if(dp[n] != 0)
        return dp[n]; 

    //  종료 조건
    if(n <= 1)
        return 0;
    if(n == 2 || n == 3)
        return 1;

    // 흐름
    int _min = INT_MAX;  // -2^31 

    // 3으로 나누어본다. 
    if(n%3==0 && dfs(n/3) < _min){
        _min = dfs(n/3);
    }
    // 2 나누어 본다. 
    if(n%2==0 && dfs(n/2) < _min){
        _min = dfs(n/2);
    }
    // 1을 빼본다.
    if(dfs(n-1) < _min){
        _min = dfs(n-1);
    }

    dp[n] = _min+1;
    return dp[n];
}

int n;
int main() {
    cin >> n;

    // 답
    int answer = dfs(n);  // dfs 함수: 깊이 탐색(재귀)

    cout << answer << '\n';
    return 0;
}
