#include <bits/stdc++.h>
using namespace std;

int dp[101][101][101];

int solution(string s1, string s2, string s3) {
    int result = 0;

    for (int i = 1; i < s1.length(); i++) {
        for (int j = 1; j < s2.length(); j++) {
            for (int k = 1; k < s3.length(); k++) {
                if ((s1[i] == s2[j]) && (s2[j]== s3[k]))
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else 
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                result = max(result, dp[i][j][k]);
            }
        }
    }
    return result;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    s1 = ' ' + s1;
    s2 = ' ' + s2;
    s3 = ' ' + s3;
    cout << solution(s1, s2, s3) << '\n';
}