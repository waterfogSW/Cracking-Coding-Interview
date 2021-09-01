#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> result;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        list<pair<int, int>> q;

        int cnt = 1;  // 몇번째로 인쇄되는지

        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            q.push_back({tmp, i});
        }

        while (!q.empty()) {
            auto c = q.front();
            q.pop_front();

            int flag = 0;
            for (auto e : q) {
                if (c.first < e.first) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1) {
                q.push_back(c);
            } else {
                if (c.second == m) break;
                else cnt++;
            }
        }

        result.push_back(cnt);
    }

    for(int i: result) {
        cout << i << '\n';
    }
}