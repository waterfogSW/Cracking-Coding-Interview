#include <bits/stdc++.h>
using namespace std;

#define MAX 1000 + 1

int n;
int arr[MAX];
int dp[MAX];

int lis_1() {  // O(n^2)
    int result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                result = max(result, dp[i]);
            }
        }
    }
    return result;
}

int lis_2() {  // O(n * log(n))
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << lis_1();
}

/* 
8
3 5 7 9 2 1 4 8
*/