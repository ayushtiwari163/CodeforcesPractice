#include <bits/stdc++.h>
using namespace std;
int kthmex(vector<int> &a, int n, int k)
{
    set<int> s;
    int i;
    for (i = 0; i < n; i++)
        s.insert(a[i]);
    vector<int> b;
    for (auto nb : s)
    {
        b.push_back(nb);
    }
    int x = 0;
    vector<int> mis;
    for (i = 0; i < b.size(); i++)
    {
        if (b[i] == x)
            x++;
        else
        {
            mis.push_back(x);
            x++;
            i--;
        }
    }
    for (auto t : mis)
        cout << t << ' ';
    if (mis.size() < k)
    {
        return b.back() + (k - mis.size());
    }
    return mis[k - 1];
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    int ans = kthmex(a, n, k);
    cout << ans << endl;
}