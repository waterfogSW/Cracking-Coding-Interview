#include <bits/stdc++.h>
using namespace std;

#define MAX 500000

int n, m;
vector<int> cd1, cd2;

bool bs(int target) {
    int mid;
    int start = 0, end = cd1.size();
    while (start <= end) {
        mid = (start + end) / 2;
        if (cd1[mid] == target) return true;
        else if(cd1[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cd1.push_back(tmp);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        cd2.push_back(tmp);
    }

    sort(cd1.begin(), cd1.end());

    for(int i : cd2) {
        cout << bs(i) << ' ';
    }

    
}