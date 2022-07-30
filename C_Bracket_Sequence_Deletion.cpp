#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define eb emplace_back
#define mp make_pair
#define ll long long
#define lld long double
#define all(x) (x).begin(), (x).end()
#define vll vector<long long int>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

//-----------------------------------------------------------

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> temp;
    vector<int> a(n, -1);
    set<int> st;

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] == -1)
            st.insert(i);
        else
            temp.pb(i);
    }
    st.clear();
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
            st.insert(i);
        else
        {
            st.insert(i);
            if (i == 0 && b[i] == 0)
                continue;
            int x = b[i] - 1;

            while (st.empty() == false)
            {
                if (x < 0)
                    break;
                int it = *st.begin();
                a[it] = x;
                st.erase(it);
                x--;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (a[i] == -1)
            a[i] = 100000000;
    int mex = 0;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
        while (s.count(mex))
        {
            mex++;
        }
        if (b[i] != -1)
        {
            if (mex == b[i])
                continue;
            else
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (auto c : a)
        cout << c << ' ';
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //	if (fopen("input.txt", "r"))
    //	{
    //		freopen("input.txt", "r", stdin);
    //		freopen("output.txt", "w", stdout);
    //	}
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}