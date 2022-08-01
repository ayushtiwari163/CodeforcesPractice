#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#include<ctype.h>
#include<vector>
#include<set>
#include<string>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ba back
#define ppb pop_back
#define eb emplace_back
#define eps 1e-6
#define vll vector<long long int>
#define sz(x) (int((x.size())))
#define all(x) (x).begin(),(x).end()
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
using namespace std;
typedef long long int ll;
ll M=1000000007;
int f=0;
int main()
{ int t;
cin>>t;

while(t--){
    int n; 
    cin>>n;
    int a[26]={0}; 
    ll x=n;
    while(n--)// yaha par n khatam ho ja raha ha iss liye n ko pahile x main store kiye ha ---2
    {
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)// yaha s.size() tak chaloge
    {
        ++a[s[i]-'a'];
    }
        
     }
     f=0;// f har test case ke liye hoga intialize
    for(int i=0;i<26;i++){
    if(a[i]%x!=0)
    {f=1;
    break;}
    }
    if(f==1)
cout<<"NO"<<endl;
else 
cout<<"YES"<<endl;
}



return 0;
}