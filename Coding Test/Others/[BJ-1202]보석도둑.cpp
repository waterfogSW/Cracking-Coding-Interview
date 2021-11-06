#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> bag(k, 0);
    vector<bool> isFull(n, 0);
    vector<pair<int, int>> gem;

    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        gem.push_back({w, v});
    }

    for (int i = 0; i < k; i++) cin >> bag[i];

    sort(bag.begin(), bag.end());
    sort(gem.begin(), gem.end());

    priority_queue<int> pq;

    long long answer = 0;
    int j = 0;
    for (int i = 0; i < k; i++) {
        while(gem[j].first <= bag[i] && j < n) {
            pq.push(gem[j].second);
            j++;
        }

        if(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer << '\n';
}