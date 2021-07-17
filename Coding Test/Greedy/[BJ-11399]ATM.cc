#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> _time;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        _time.push_back(temp);
    }

    sort(_time.begin(), _time.end());

    
    int sum = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        sum += _time[i];
        result += sum;
    }
    
    cout << result;
    
}