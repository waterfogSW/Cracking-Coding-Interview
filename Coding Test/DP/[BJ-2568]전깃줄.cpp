#include <bits/stdc++.h>
using namespace std;

int lower_bound(int arr[], int size, int target) {
    int start, mid, end;
    start = 0;
    end = size - 1;
    while (start < end) {
        mid = (start + end) / 2;
        if (arr[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }
    return end;
}

vector<int> lis(int n, vector<int> &arr) {
    int size = 1;
    int *dp = new int[n + 1];
    int *idx = new int[n + 1];
    vector<int> result;

    dp[0] = arr[1];
    for (int i = 1; i <= n; i++) {
        if (dp[size - 1] < arr[i]) {
            idx[i] = size;
            dp[size++] = arr[i];
        } else {
            idx[i] = lower_bound(dp, size, arr[i]);
            dp[idx[i]] = arr[i];
        }
    }

    size -= 1;
    for(int i = n; i >= 0; i--) {
        if(idx[i] == size) {
            size -= 1;
            result.push_back(arr[i]);
        }
    }
    sort(result.begin(), result.end());
    return result;
}

void solution(int n) {
    vector<int> tmp;
    vector<pair<int, int>> arr(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr.begin(), arr.end());
    for (auto i : arr) tmp.push_back(i.second);

    tmp = lis(n, tmp);
    cout << arr.size() - tmp.size() - 1 << '\n';


    int index = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i].second == tmp[index]) {
            index++;
        } else {
            cout << arr[i].first << '\n';
        }
    }
}

int main() {
    int n;
    cin >> n;
    solution(n);
}