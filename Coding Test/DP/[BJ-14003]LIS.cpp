#include <bits/stdc++.h>
using namespace std;

/*
LIS : Longest Increasing Subsequence
어떤 수열에 대해 해당 수열에서 일부 원소를 뽑아 만든 수열을 부분수열이라 하며,
해당 수열이 오름차순으로 증가하는 경우 LIS라 한다.

## lis : n^2 
a[i]보다 a[j]의 값이 작을 경우 dp[i] = max(dp[i], dp[j] + 1)로 
a[i]전까지 확인된 LIS중 최댓값 + 1 로 a[i]값을 정의한다.

## lis : log_n
앞선 방식의 경우 lis를 갱신할때 마다 현재까지 확인된 LIS를 모두 조회해야 하므로 
시간복잡도가 증가한다. 

LIS의 마지막 원소가 가능한 작을수록 더 긴 LIS를 생성할 수 있으므로
LIS의 마지막 원소보다 작은경우 lower_bound로 인덱스를 찾아 갱신하고(최소값으로 갱신)
LIS의 마지막 원소보다 큰경우 LIS의 길이를 증가시킨다.

## lis_store

*/

int LB(int arr[], int size, int target) {  // lower bound
    int start, mid, end;
    start = 0;
    end = size - 1;
    while (end > start) {
        mid = (start + end) / 2;
        if (arr[mid] >= target)
            end = mid;
        else
            start = mid + 1;
    }
    return end;
}

int lis_2(int n, vector<int> &arr) {
    int result = 1;
    int *dp = new int[n + 1]();

    dp[0] = arr[1];
    for (int i = 1; i <= n; i++) {
        if (dp[result - 1] < arr[i])
            dp[result++] = arr[i];
        else
            dp[LB(dp, result, arr[i])] = arr[i];
    }
    return result;
}

vector<int> lis_3(int n, vector<int> &arr) {
    int size = 1;
    int *dp = new int[n + 1]();
    int *idx = new int[n + 1]();
    vector<int> result;

    dp[0] = arr[1];
    for (int i = 1; i <= n; i++) {
        if (dp[size - 1] < arr[i]) {
            idx[i] = size;
            dp[size++] = arr[i];
        } else {
            idx[i] = LB(dp, size, arr[i]);
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

int main() {
    int n;
    cin >> n;
    vector<int> arr = {0};
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    auto result = lis_3(n, arr);
    cout << result.size() << '\n';
    for(int i : result) {
        cout << i << ' ';
    }
    cout << '\n';
}
/*
6
50 10 20 30 10 20
*/