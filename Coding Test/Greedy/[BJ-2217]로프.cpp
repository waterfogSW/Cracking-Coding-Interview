#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int n, res;
vector<int> rope;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        rope.push_back(temp);
    }

    sort(rope.begin(), rope.end());
    for (int i = 0; i < rope.size(); i++) {
        int sum = rope[i] * (rope.size() - i);
        res = max(res, sum);
    }

    cout << res;
}