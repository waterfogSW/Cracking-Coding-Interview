#include <bits/stdc++.h>
using namespace std;

int k, n;
vector<long long> lines;

long long cut(long long x) {
    long long count = 0;
    if(x == 0) return lines.size();
    for (long long line : lines) {
        count += line / x;
    }
    return count;
}

int main() {
    cin >> k >> n;
    for (long long i = 0; i < k; i++) {
        long long tmp;
        cin >> tmp;
        lines.push_back(tmp);
    }

    long long start = 0;
    long long end = LONG_LONG_MAX;
    long long mid;
    long long res = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        if (cut(mid) >= n) {
            if(res < mid) res = mid;
            start = mid + 1;
        } else
            end = mid - 1;
    }
    cout << res;
}