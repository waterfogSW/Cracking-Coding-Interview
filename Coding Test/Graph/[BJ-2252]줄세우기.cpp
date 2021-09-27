#include <bits/stdc++.h>
using namespace std;

#define MAX 32001

int main() {
    int n, m;

    cin >> n >> m;

    auto graph = new vector<int>[n + 1]();
    auto degree = new int[n + 1]();
    auto visit = new bool[n + 1]();

    for(int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        degree[end]++;
    }

    queue<int> tp;
    
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 0) {
            tp.push(i);
            visit[i] = 1;
        }
    }

    while(!tp.empty()) {
        int c = tp.front(); tp.pop();

        cout << c << ' ';

        for(int i : graph[c]) {
            degree[i]--;
            if(degree[i] == 0 && !visit[i]) {
                tp.push(i);
                visit[i] = 1;
            }
        }
    }

}