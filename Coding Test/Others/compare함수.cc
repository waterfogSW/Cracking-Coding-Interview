#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<string, int>> student;

string tmp_name;
int tmp_score;

bool compare(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp_name >> tmp_score;
        student.push_back(make_pair(tmp_name, tmp_score));
    }

    sort(student.begin(), student.end(), compare);

    for (int i = 0; i < student.size(); i++) {
        cout << student[i].first;
    }

}
