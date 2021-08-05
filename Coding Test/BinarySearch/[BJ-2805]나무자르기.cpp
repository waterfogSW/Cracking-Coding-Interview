#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> tree;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        tree.push_back(tmp);
    }

    sort(tree.begin(), tree.end());

    long long right = tree.back();
    long long left = tree.front();

    long long mid = right / 2, result = 0;

    while (right >= left) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (tree[i] > mid) sum += tree[i] - mid;
        }
        if (sum >= m) {
            if (result < mid) result = mid;
            left = mid + 1;
            mid = (left + right) / 2;
        } else {
            right = mid - 1;
            mid = (left + right) / 2;
        }
    }
    cout << result << '\n';

    return 0;
}