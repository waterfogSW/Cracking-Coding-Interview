#include <bits/stdc++.h>
using namespace std;

bool isGroup(const string &s) {
    bool group[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        int idx = s[i] - 97;

        if (group[idx]) {
            return 0;
        } 
        
        else {
            group[idx] = 1;
            char start = s[i];
            while (start == s[i + 1]) {
                i++;
            }
        }
    }
    return 1;
}

int solution() {
    int n;
    cin >> n;
    vector<string> ss;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        ss.push_back(tmp);
    }

    int result = 0;
    for (string s : ss) {
        if (isGroup(s)) result++;
    }

    return result;
}

int main() {
    cout << solution() << '\n';
}