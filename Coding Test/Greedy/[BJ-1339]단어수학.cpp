#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> letter(26);
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.length(); j++)
        {
            letter[temp[j] - 'A'] += pow(10, temp.length() - 1 - j);
        }
    }

    sort(letter.begin(), letter.end());

    int ans = 0;
    int priority = 9;
    for (int i = letter.size() - 1; i > 0; i--)
    {
        if (letter[i] == 0) break;
        ans += priority * letter[i];
        priority--;
    }
    cout << ans << '\n';
}

