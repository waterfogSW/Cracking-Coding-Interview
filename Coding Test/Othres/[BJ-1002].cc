#include <bits/stdc++.h>
using namespace std;

struct T {
    int x1, y1, r1;
    int x2, y2, r2;
};

int main() {
    int n;
    cin >> n;
    struct T t[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i].x1 >> t[i].y1 >> t[i].r1 >> t[i].x2 >> t[i].y2 >> t[i].r2;
    }

    for (int i = 0; i < n; i++) {
        int answer = 0;

        long long dist = pow(t[i].x1 - t[i].x2, 2) + pow(t[i].y1 - t[i].y2, 2);
        long long rdist1 = pow(t[i].r1 - t[i].r2, 2);
        long long rdist2 = pow(t[i].r1 + t[i].r2, 2);

       //1 cout << dist << rdist1 << rdist2 << '\n';
        
        if((rdist1 < dist) &&( dist < rdist2)) {
            cout << '2' << '\n';
        } else if ((rdist1 == dist || rdist2 == dist) && dist != 0) {
            cout << '1' << '\n';
        } else if (rdist1 > dist || dist > rdist2){
            cout << '0' << '\n';
        } else {
            cout << "-1" << '\n';
        }
    }
}