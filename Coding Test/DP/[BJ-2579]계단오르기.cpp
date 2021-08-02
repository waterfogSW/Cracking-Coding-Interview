#include <bits/stdc++.h>
using namespace std;

int num;
int score[300];
int dp[300];
int main() {
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> score[i];
    }

    // 계단은 연속으로 3개를 밟을수는 없다.
    dp[0] = score[0];
    dp[1] = score[0] + score[1];

    //자기 자신은 항상 계산한 모든값중 최대이기 때문에 포함하는것으로 한다.
    dp[2] = max(score[0] + score[2], score[1] + score[2]);

    for (int i = 3; i < num; i++) {
        dp[i] = max(score[i] + dp[i-2], score[i] + score[i-1] + dp[i-3]);
    }

    cout << dp[num - 1];
}