#include <bits/stdc++.h>
using namespace std;

#define M1 1000000007
#define M2 998244353
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
//#define G(a,b) get<a>(b)
#define V(a) vector<a>

//static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */

    ll ntc=1;
    cin>>ntc;
    REP(tc,1,ntc+1)
    {
        //cout<<"Case #"<<tc<<": ";

        ll n,m;
        cin>>n>>m;
        string s[n];
        REP(i,0,n)
        {
            cin>>s[i];
        }
        V(V(pll)) ans;
        REP(i,0,n-2)
        {
            REP(j,0,m-1)
            {
                if(s[i][j]=='1')
                {
                    V(pll) tmp;
                    tmp.PB(MP(i,j));
                    tmp.PB(MP(i,j+1));
                    tmp.PB(MP(i+1,j));
                    ans.PB(tmp);
                    for(auto it:tmp)
                    {
                        s[it.F][it.S]=(1-(s[it.F][it.S]-'0'))+'0';
                    }
                }
            }
            if(s[i][m-1]=='1')
            {
                V(pll) tmp;
                tmp.PB(MP(i,m-1));
                tmp.PB(MP(i+1,m-1));
                tmp.PB(MP(i+1,m-2));
                ans.PB(tmp);
                for(auto it:tmp)
                {
                    s[it.F][it.S]=(1-(s[it.F][it.S]-'0'))+'0';
                }
            }
        }
        REP(j,0,m-2)
        {
            if(s[n-2][j]=='1'&&s[n-1][j]=='1')
            {
                V(pll) tmp;
                tmp.PB(MP(n-2,j));
                tmp.PB(MP(n-1,j));
                tmp.PB(MP(n-2,j+1));
                ans.PB(tmp);
                for(auto it:tmp)
                {
                    s[it.F][it.S]=(1-(s[it.F][it.S]-'0'))+'0';
                }
            }
            else if(s[n-2][j]=='1')
            {
                V(pll) tmp;
                tmp.PB(MP(n-2,j));
                tmp.PB(MP(n-1,j+1));
                tmp.PB(MP(n-2,j+1));
                ans.PB(tmp);
                for(auto it:tmp)
                {
                    s[it.F][it.S]=(1-(s[it.F][it.S]-'0'))+'0';
                }
            }
            else if(s[n-1][j]=='1')
            {
                V(pll) tmp;
                tmp.PB(MP(n-1,j));
                tmp.PB(MP(n-1,j+1));
                tmp.PB(MP(n-2,j+1));
                ans.PB(tmp);
                for(auto it:tmp)
                {
                    s[it.F][it.S]=(1-(s[it.F][it.S]-'0'))+'0';
                }
            }
        }
        if(s[n-1][m-1]=='1'&&s[n-1][m-2]=='1'&&s[n-2][m-1]=='1'&&s[n-2][m-2]=='1')
        {
            V(pll) tmp;
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-2,m-2));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='1'&&s[n-1][m-2]=='1'&&s[n-2][m-1]=='1'&&s[n-2][m-2]=='0')
        {
            V(pll) tmp;
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-1));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='1'&&s[n-1][m-2]=='1'&&s[n-2][m-1]=='0'&&s[n-2][m-2]=='1')
        {
            V(pll) tmp;
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='1'&&s[n-1][m-2]=='0'&&s[n-2][m-1]=='1'&&s[n-2][m-2]=='1')
        {
            V(pll) tmp;
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-2,m-2));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='0'&&s[n-1][m-2]=='1'&&s[n-2][m-1]=='1'&&s[n-2][m-2]=='1')
        {
            V(pll) tmp;
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='1'&&s[n-1][m-2]=='1'&&s[n-2][m-1]=='0'&&s[n-2][m-2]=='0')
        {
            V(pll) tmp;
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-1,m-2));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='0'&&s[n-1][m-2]=='0'&&s[n-2][m-1]=='1'&&s[n-2][m-2]=='1')
        {
            V(pll) tmp;
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-2,m-1));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='1'&&s[n-1][m-2]=='0'&&s[n-2][m-1]=='1'&&s[n-2][m-2]=='0')
        {
            V(pll) tmp;
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='0'&&s[n-1][m-2]=='1'&&s[n-2][m-1]=='0'&&s[n-2][m-2]=='1')
        {
            V(pll) tmp;
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='0'&&s[n-1][m-2]=='1'&&s[n-2][m-1]=='1'&&s[n-2][m-2]=='0')
        {
            V(pll) tmp;
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='1'&&s[n-1][m-2]=='0'&&s[n-2][m-1]=='0'&&s[n-2][m-2]=='1')
        {
            V(pll) tmp;
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-1,m-1));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='1'&&s[n-1][m-2]=='0'&&s[n-2][m-1]=='0'&&s[n-2][m-2]=='0')
        {
            V(pll) tmp;
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-1));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='0'&&s[n-1][m-2]=='1'&&s[n-2][m-1]=='0'&&s[n-2][m-2]=='0')
        {
            V(pll) tmp;
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='0'&&s[n-1][m-2]=='0'&&s[n-2][m-1]=='1'&&s[n-2][m-2]=='0')
        {
            V(pll) tmp;
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            ans.PB(tmp);
        }
        else if(s[n-1][m-1]=='0'&&s[n-1][m-2]=='0'&&s[n-2][m-1]=='0'&&s[n-2][m-2]=='1')
        {
            V(pll) tmp;
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            tmp.PB(MP(n-2,m-1));
            tmp.PB(MP(n-1,m-1));
            tmp.PB(MP(n-1,m-2));
            tmp.PB(MP(n-2,m-2));
            ans.PB(tmp);
        }
        V(pll) ansss;
        for(auto it:ans)
        {
            for(auto itt:it) ansss.PB(itt);
        }
        cout<<((ll)ansss.size())/3<<'\n';
        REP(i,0,((ll)ansss.size()))
        {
            REP(j,0,3)
            {
                cout<<ansss[i+j].F+1<<' '<<ansss[i+j].S+1<<' ';
            }
            i+=2;
            cout<<'\n';
        }
        

        cout<<'\n';
    }

    return 0;
}
