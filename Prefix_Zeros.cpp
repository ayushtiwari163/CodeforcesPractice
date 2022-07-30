#include <bits/stdc++.h>
using namespace std;
// function finds the number of wondeful sunstring
int countWonderfulString(string s)
{
    unordered_map<int, int> seen;
    seen[0] = 1;
    int mask = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        mask ^= (1 << (s[i] - 'a'));
        ans += seen[mask];
        for (int j = 0; j < 10; ++j)
        {
            ans += seen[mask ^ (1 << j)];
        }
        seen[mask]++;
    }
    return ans;
}
// driver code
int main()
{
    string s;
    cin >> s;
    int ans = countWonderfulString(s);
    cout << "Number of Wonderful substrings: " << ans;
}