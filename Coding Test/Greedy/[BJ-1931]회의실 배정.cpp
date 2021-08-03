#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<pair<int, int>> info;
vector<pair<int, int>> v;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int start = 0;
        int end = 0;
        
        cin >> start >> end;
        info.push({-end, -start});
    }

    v.push_back({-info.top().second, -info.top().first});
    info.pop();

    while (!info.empty()) {
        int start = -info.top().second;
        int end = -info.top().first;

        if (v.back().second <= start)
            v.push_back({start, end});
        
        info.pop();
    }

    cout << v.size() << '\n';
}