//세그먼트 트리
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr(10000000);
vector<int> minTree(10000000);
vector<int> maxTree(10000000);

int minInit(int node, int start, int end) {
    if (start == end) {
        return minTree[node] = arr[start];
    } else {
        return minTree[node] = min(minInit(node * 2, start, (start + end) / 2),
                                   minInit(node * 2 + 1, (start + end) / 2 + 1, end));
    }
}

int maxInit(int node, int start, int end) {
    if (start == end) {
        return maxTree[node] = arr[start];
    } else {
        return maxTree[node] = max(maxInit(node * 2, start, (start + end) / 2),
                                   maxInit(node * 2 + 1, (start + end) / 2 + 1, end));
    }
}

int _min(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return INT_MAX;
    if (left <= start && end <= right) return minTree[node];
    return min(_min(node * 2, start, (start + end) / 2, left, right),
               _min(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int _max(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return INT_MIN;
    if (left <= start && end <= right) return maxTree[node];
    return max(_max(node * 2, start, (start + end) / 2, left, right),
               _max(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        q.push({start, end});
    }

    minInit(1, 0, n - 1);
    maxInit(1, 0, n - 1);

    while (!q.empty()) {
        int p1 = q.front().first;
        int p2 = q.front().second;
        q.pop();
        cout << _min(1, 0, n - 1, p1 - 1, p2 - 1) << ' ';
        cout << _max(1, 0, n - 1, p1 - 1, p2 - 1) << '\n';
    }
}