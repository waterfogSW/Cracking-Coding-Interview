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
    root[x] = y;
}

int solution(int n) {
    int result = 0;
    int *root = new int[n];
    vector<pair<int, int>> x, y, z;
    priority_queue<tuple<int, int, int>> pq;

    for(int i = 0; i < n; i++) root[i] = i;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for (int i = 1; i < n; i++) {
        int costX = abs(x[i].first - x[i - 1].first);
        int costY = abs(y[i].first - y[i - 1].first);
        int costZ = abs(z[i].first - z[i - 1].first);

        pq.push({-costX, x[i].second, x[i - 1].second});
        pq.push({-costY, y[i].second, y[i - 1].second});
        pq.push({-costZ, z[i].second, z[i - 1].second});
    }

    while (!pq.empty()) {
        int w = -get<0>(pq.top());
        int a = get<1>(pq.top());
        int b = get<2>(pq.top());
        pq.pop();
        if(Find(a,root) != Find(b, root)) {
            Union(a, b, root);
            result += w;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    cout << solution(n);
}