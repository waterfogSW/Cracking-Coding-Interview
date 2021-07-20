#include <bits/stdc++.h>
using namespace std;

int dp[10+1];

int dfs(int n){
    if(dp[n] != 0)
        return dp[n];

    // 종료 조건
    if(n < 0)
        return 0;
    if(n==0)
        return 1;

    dp[n] = dfs(n-1) + dfs(n-2) + dfs(n-3); 
    return dp[n];

}


int t;
queue<int> q;

int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        int n;        
        cin >> n;
        q.push(n);
    }
    
    while(!q.empty()){
 
        cout << dfs(q.front()) << '\n'; q.pop();
    }

}
