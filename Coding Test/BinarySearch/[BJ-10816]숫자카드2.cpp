#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> cd1, cd2;

int bs_up(int target) {
    int start = 0;
    int end = cd1.size();
    int mid;

    while (start < end) {
        mid = (start + end) / 2;
        if (cd1[mid] <= target)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

int bs_low(int target) {
    int start = 0;
    int end = cd1.size();
    int mid;

    while (start < end) {
        mid = (start + end) / 2;
        if (cd1[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    return start;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cd1.push_back(temp);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        cd2.push_back(temp);
    }

    sort(cd1.begin(), cd1.end());

    for (int i : cd2) {
        cout << bs_up(i) - bs_low(i) << ' ';
    }
}