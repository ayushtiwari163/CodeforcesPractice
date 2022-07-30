
#include <bits/stdc++.h>
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)

using namespace std;
    
vector<int> ans(1000005,0); 
vector<int> prime(1000005,1); 

void seive()
{
    
    long long int i,j;
    ans[2]=1;
    for(i=3;i<=1000002;i++)
    {
         if(i%2==0)
         {
             prime[i]=0;
             ans[i]+=ans[i-1];
             continue;
         }
        if(prime[i]){
            ans[i]++;
        for(j=(i*i);j<=1000002;j=j+i)
        prime[j]=0;
        
        }
        ans[i]+=ans[i-1];
    }
}  


int main() {
FAST;
int t;
t=1;
seive();

cin>>t;
while(t--)
{
  int n;
  cin>>n;
  int x=sqrt(n);
   int val=ans[n]-ans[x]+1;
   cout<<val<<endl;
}
}