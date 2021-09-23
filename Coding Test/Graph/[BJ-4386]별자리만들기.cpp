#include <bits/stdc++.h>
using namespace std;

typedef pair<float, float> pairFloat;

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

float getCost(pairFloat a, pairFloat b) {
    float xDist = pow(a.first - b.first, 2);
    float yDist = pow(a.second - b.second, 2);
    return sqrt(xDist + yDist);
}

float solution(int n) {
    float result = 0;
    int *root = new int[n]();
    vector<pairFloat> star;
    priority_queue<tuple<float, int, int>> pq;
    for (int i = 0; i < n; i++) root[i] = i;

    for (int i = 0; i < n; i++) {
        float x, y;
        cin >> x >> y;
        star.push_back({x, y});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pq.push({-getCost(star[i], star[j]), i, j});
        }
    }

    while (!pq.empty()) {
        float w = -get<0>(pq.top());
        int a = get<1>(pq.top());
        int b = get<2>(pq.top());
        pq.pop();
        if (Find(a, root) != Find(b, root)) {
            result += w;
            Union(a, b, root);
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    printf("%.2f\n", solution(n));
}