#include <bits/stdc++.h>
using namespace std;

#define MAX_FRIEND 501

bool isIn(int x, vector<int> &arr) {
    for (int i : arr) {
        if (i == x) return true;
    }
    return false;
}

int solution() {
    int n, m;  // 동기의 수, 리스트의 길이
    vector<int> f[MAX_FRIEND];
    vector<int> result;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int f1, f2;
        cin >> f1 >> f2;
        f[f1].push_back(f2);
        f[f2].push_back(f1);
    }
    result = f[1];

    for (int f1 : f[1]) {
        for (int f2 : f[f1]) {
            if (!isIn(f2, result) && f2 != 1) {
                result.push_back(f2);
            }
        }
    }

    return result.size();
}

int main() {
    cout << solution() << '\n';
}