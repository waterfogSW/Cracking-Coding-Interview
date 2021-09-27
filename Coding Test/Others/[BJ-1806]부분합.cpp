#include <bits/stdc++.h>
using namespace std;

int solution(int n, int s, int arr[]) {
    int result = INT_MAX, end = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        while (sum < s && end < n) sum += arr[end++];
        if (sum >= s) result = min(result, end - i);
        sum -= arr[i];
    }
    return result == INT_MAX ? 0 : result;
}

int main() {
    int n, s;
    cin >> n >> s;
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solution(n, s, arr) << '\n';
}