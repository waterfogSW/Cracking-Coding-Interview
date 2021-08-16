#include <bits/stdc++.h>
using namespace std;

string str1, str2;
int lcs[1000 + 1][1000 + 1];
int _max;

// 최장 공통 문자열
void lc_string() {
    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if (str1[i] == str2[j]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
                _max = max(_max, lcs[i][j]);
            } else
                lcs[i][j] = 0;
        }
    }
}

// 최장 공통 부분 수열
void lc_subsequence() {
    for (int i = 1; i < str1.length(); i++) {
        for (int j = 1; j < str2.length(); j++) {
            if (str1[i] == str2[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
            _max = max(_max, lcs[i][j]);
        }
    }
}

int main() {
    cin >> str1 >> str2;

    str1 = ' ' + str1;
    str2 = ' ' + str2;

    cout << str1 << '\n' << str2 << '\n';

    int len1 = str1.length();
    int len2 = str2.length();

    lc_subsequence();


    cout << _max;
}