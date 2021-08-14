#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int n, m;
vector<int> graph[MAX];
bool _visit[MAX];

void dfs(int x) {
    if (_visit[x]) return;
    _visit[x] = true;
    for (int i : graph[x]) {
        dfs(i);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (!_visit[i]) {
            result++;
            dfs(i);
        }
    }
    cout << result;
}