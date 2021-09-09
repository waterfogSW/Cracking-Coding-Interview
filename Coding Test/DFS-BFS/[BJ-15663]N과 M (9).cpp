#include <bits/stdc++.h>
using namespace std;

int n, m;
bool v[10000];
vector<int> arr, res;

void dfs(int x) {
    if (x == m) {
        for (int i : res) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    
    int prev = -1;

    for (int i = 0; i < n; i++) {
        if (!v[i] && prev != arr[i]) {
            v[i] = 1;
            res.push_back(arr[i]);
            prev = arr[i];

            dfs(x + 1);

            v[i] = 0;
            res.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    dfs(0);
}
