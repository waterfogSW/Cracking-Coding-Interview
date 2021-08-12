#include <bits/stdc++.h>
using namespace std;

string _exp;
vector<int> arr;
int res;

int main() {
    int sum = 0;
    string temp = "";

    cin >> _exp;

    for (int i = 0; i < _exp.size(); i++) {
        temp += _exp[i];

        if (_exp[i] == '+' || _exp[i] == '-' || i == _exp.size() - 1) {
            sum += stoi(temp);
            temp = "";
            if (_exp[i] == '-' || i == _exp.size() - 1) {
                arr.push_back(sum);
                sum = 0;
            }
        }
    }

    res = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        res -= arr[i];
    }

    cout << res;
}