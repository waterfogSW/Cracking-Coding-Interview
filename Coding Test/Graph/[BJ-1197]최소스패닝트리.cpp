#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Find(int a, int *root) {
    if (root[a] == a)
        return a;
    else
        return root[a] = Find(root[a], root); // 재귀 감소
}

void Union(int x, int y, int *root) {
    x = Find(x, root);
    y = Find(y, root);
    root[y] = x;
}

ll solution(int v, int e) {
    ll result = 0;
    int *root = new int[v + 1];
    for (int i = 1; i <= v; i++) root[i] = i;

    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
    }

    while(!pq.empty()) {
        int w = -get<0>(pq.top());
        int v1 = get<1>(pq.top());
        int v2 = get<2>(pq.top());
        pq.pop();
        if(Find(v1,root) != Find(v2,root)) {
            Union(v1,v2, root);
            result += w;
        }
    }
    return result;
}

int main() {
    int v, e;
    cin >> v >> e;
    cout << solution(v, e) << '\n';
}