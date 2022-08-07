#include <bits/stdc++.h>
using namespace std;
map<int, string> mp;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26, 0);
    map<int, pair<int, char>> m;
    m[0] = {0, 'z'};
    m[1] = {2, 'w'};
    m[2] = {6, 'x'};
    m[4] = {7, 's'};
    m[5] = {8, 'g'};
    m[6] = {3, 't'};
    m[7] = {4, 'u'};
    m[8] = {1, 'o'};
    m[9] = {9, 'n'};
    int i;
    for (i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    // for (i = 0; i < 26; i++)
    //     cout << cnt[i] << ' ';
    vector<int> ans(10, 0);
    int digit = 0;
    for (auto nb : m)
    {
        string temp = mp[nb.second.first];
        // cout << temp << ' ';
        char p = nb.second.second;
        int x = cnt[p - 'a'];
        for (i = 0; i < temp.size(); i++)
        {
            cnt[temp[i] - 'a'] -= x;
        }
        ans[nb.second.first] = x;
        digit = digit + x;
    }

    if (digit == ans[0])
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (ans[i] != 0)
        {
            ans[i]--;
            cout << i;
            break;
        }
    }
    digit--;
    while (digit--)
    {
        for (int i = 0; i <= 9; i++)
        {
            if (ans[i] != 0)
            {
                ans[i]--;
                cout << i;
                break;
            }
        }
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    mp[0] = "zero";
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";

    while (t--)
        solve();
}