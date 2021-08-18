#include <bits/stdc++.h>
using namespace std;

int n, res;
int arr[1000], dp1[1000], dp2[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int k = 0; k < n; k++) {
        dp1[k] = 1;
        for (int i = 0; i < k; i++) {
            if (arr[i] < arr[k])
                dp1[k] = max(dp1[k], dp1[i] + 1);
        }
    }

    for (int k = n - 1; k >= 0; k--) {
        dp2[k] = 0;
        for (int i = n - 1; i > k; i--) {
            if (arr[i] < arr[k])
                dp2[k] = max(dp2[k], dp2[i] + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        res = max(res, dp1[i] + dp2[i]);
    }

    cout << res;
}