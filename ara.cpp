#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);

    ll i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
    map<ll, vector<ll>> m;

    for (i = 0; i < n; i++)
    {
        m[a[i]].push_back(b[i]);
    }
    ll ans = 0;
    for (auto nb : m)
    {
        vector<ll> temp = nb.second;
        sort(temp.begin(), temp.end());
        for (i = 0; i < temp.size() - 1; i++)
        {
            ans = ans + temp[i];
            m[nb.first + 1].push_back(temp[i]);
        }
    }
    cout << ans << endl;
}