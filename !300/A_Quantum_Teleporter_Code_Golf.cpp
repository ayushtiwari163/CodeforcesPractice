#include <iostream> 
using namespace std;int main(){int n;cin>>n;int t=0,a =0;while((t+1)<(n-a-t-1)){a+=(t+1);t++;}while((n-a)!=(t+1))t++;cout<<t+1;}
