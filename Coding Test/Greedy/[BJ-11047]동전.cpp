#include <bits/stdc++.h>
using namespace std;

int n, k;
int coin[10];
int _cnt;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    int i = 1;
    while (k > 0 && i <= n) {
        if (coin[n - i] <= k) {
            k -= coin[n - i];
            _cnt++;
        } else {
            i++;
        }
    }
    cout << _cnt;
}