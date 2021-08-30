#include <bits/stdc++.h>
using namespace std;

int t, n;
int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;


        vector<pair<int, int>> cand;
        for (int j = 0; j < n; j++) {
            int sc1, sc2;
            cin >> sc1 >> sc2;

            cand.push_back({sc1, sc2});
        }

        sort(cand.begin(), cand.end());

        int res = 1;
        int std = cand[0].second;
        for(int i = 1; i < n; i++) {
            if(std >= cand[i].second) {
                std = cand[i].second;
                res++;
            }
        }

        cout << res << '\n';
    }
}