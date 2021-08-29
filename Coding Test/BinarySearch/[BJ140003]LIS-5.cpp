#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

int arr[MAX], lis[MAX], p[MAX], len, n;
void backtrace(int idx, int num) {
    if (idx == 0)
        return;
    if (p[idx] == num) {
        backtrace(idx - 1, num - 1);
        cout << arr[idx] << " ";
    } else {
        backtrace(idx - 1, num);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        auto pos = lower_bound(lis + 1, lis + len + 1, arr[i]);
        *pos = arr[i];
        p[i] = distance(lis, pos);
        if (pos == lis + len + 1)
            len++;
    }
    cout << len << "\n";
    backtrace(n, len);
    return 0;
}