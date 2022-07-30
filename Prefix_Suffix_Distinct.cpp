#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int p=0;
    while(input1[p]!='\0')
    {  
        s.push_back(input1[p]);
        p++;
    }
    
    string s;
    cin >> s;
    ll m, n;
    cin >> m >> n;
    ll turn = 0;
    ll sz = (ll)s.size();
    string temp = s.substr(sz - m, m);
    temp += s.substr(0, (sz - m));
    ll ans = 1;

    while (temp != s)
    {
        string t1;
        if (turn == 0)
        {
            t1 = temp.substr(sz - n, n);
            t1 += temp.substr(0, (sz - n));
        }
        else
        {
            t1 = temp.substr(sz - m, m);
            t1 += temp.substr(0, (sz - m));
        }
        temp = t1;
        turn = 1 - turn;
        ans++;
    }
    cout << ans << endl;
}