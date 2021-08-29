#include <bits/stdc++.h>
using namespace std;

vector<long long> a(1000001);
vector<long long> tree(1 << 21);

int n, m, k;

long long init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(node * 2, start, (start + end) / 2) +
                            init(node * 2 + 1, (start + end) / 2 + 1, end);
    }
}
void update(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(node * 2, start, (start + end) / 2, index, diff);
        update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}
long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sum(node * 2, start, (start + end) / 2, left, right) +
           sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> result;

    init(1, 0, n - 1);
    for (int i = 0; i < m + k; i++) {
        long long t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if (t1 == 1) {
            update(1, 0, n - 1, t2, t3 - a[--t2]);
        } else if (t1 == 2) {
            result.push_back(sum(1, 0, n - 1, t2 - 1, t3 - 1));
        }
    }

    for (auto i : result) {
        cout << i << '\n';
    }

    return 0;
}