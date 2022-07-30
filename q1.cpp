#include<bits/stdc++.h>
using namespace std;
vector<long> bitwiseEquation(vector<long> a,vector<long> b)
{
    vector<long> ans;
    long n=a.size();
    long i;
    for(i=0;i<n;i++)
    {
        if(a[i]>=b[i])
        {
            if(a[i]%2==b[i]%2)
            {
                long x=(a[i]-b[i])/2;
                long y=x+b[i];
               // cout<<x<<' '<<y<<endl;
                if(x+y==a[i] && (x^y)==b[i])
                ans.push_back(2*x+3*y);
                else 
                ans.push_back(0);
            }
            else 
            ans.push_back(0);
        }
        else 
        ans.push_back(0);
    }
    return ans;
}
int main()
{

long n;
cin>>n;
  vector<long> a(n),b(n);
  for(long i=0;i<n;i++) cin>>a[i];
  for(long i=0;i<n;i++) cin>>b[i];
  vector<long> ans=bitwiseEquation(a,b);
  for(auto x : ans) cout<<x<<' ';

  }