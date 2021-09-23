#include <bits/stdc++.h>
using namespace std;

int Find(int a, int root[]) {
    if (root[a] == a)
        return a;
    else
        return root[a] = Find(root[a], root);
}

void Union(int x, int y, int root[]) {
    x = Find(x, root);
    y = Find(y, root);
    root[y] = x;
}

int solution(int n, int m) {
    int result = 0;
    int *root = new int[n + 1];
    priority_queue<tuple<int, int, int>> pq;

    for (int i = 1; i <= n; i++) root[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
    }

    while (!pq.empty()) {
        int w = -get<0>(pq.top());
        int a = get<1>(pq.top());
        int b = get<2>(pq.top());
        pq.pop();

        if (Find(a, root) != Find(b, root)) {
            Union(a, b, root);
            result += w;
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << solution(n, m) << '\n';
}