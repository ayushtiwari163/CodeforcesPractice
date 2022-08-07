#include <bits/stdc++.h>
using namespace std;
class union_find
{
    int n;
    vector<int> par;
    vector<int> sz;

public:
    union_find(int nval)
    {
        n = nval;
        par.resize(n + 1);
        sz.resize(n + 1);

        for (int i = 1; i <= n; ++i)
            par[i] = i, sz[i] = 1;
    }

    // O(1) ammortized
    int root(int x)
    {
        /*while(x!=par[x])
            x=par[x];
        return x;*/

        if (x == par[x])
            return x;

        return par[x] = root(par[x]);
    }

    // O(1) ammortized
    bool find(int a, int b)
    {
        return root(a) == root(b);
    }

    // O(1) ammortized
    void un(int a, int b)
    {
        int ra = root(a);
        int rb = root(b);

        if (ra == rb)
            return;

        if (sz[ra] > sz[rb])
            swap(ra, rb);

        par[ra] = rb;
        sz[rb] += sz[ra];
    }
};

int main()
{
    int c, r, q;
    cin >> c >> r >> q;
    int i;
    union_find obj(c);
    for (i = 0; i < r; i++)
    {
        int u, v;
        cin >> u >> v;
        obj.un(u, v);
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (obj.find(u, v))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}