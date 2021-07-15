#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

int a[100000];
int b[100000];

bool compare(int a, int b){
    return a > b;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) { cin >> a[i]; }
    for (int i = 0; i < n; i++) { cin >> b[i]; }

    sort(a,  a+n); 
    sort(b,  b+n, compare);

    for(int i=0; i<k; i++){
        if(a[i] > b[i])
            break;
        swap(a[i], b[i]);
    }
    long long ans = 0;
    for(auto& n : a) {
        ans += n;
    }
    cout << ans;
}
