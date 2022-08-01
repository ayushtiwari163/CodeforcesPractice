#include<bits/stdc++.h>
using namespace std;


int main(){
    
    
    int t;
    cin>>t;
    
    while(t--){
        
        int n,c;
        
        cin>>n>>c;
        
        vector <int> v1(n);
        vector <int> v2(n);
        
        
        for(int &i:v1){
            cin>>i;
        }
        for(int &i:v2){
            cin>>i;
        }
        
        vector <tuple<double,int,int>> v;
        
        for(int i=0;i<n;i++){
            
            v.push_back(make_tuple(double(v2[i])/v1[i],v1[i],v2[i]));
        }
        
        sort(v.begin(),v.end());
        
        // for(int i=0;i<n;i++){
            
        //     cout<<get<0>(v[i])<<" ";
        // }
        cout<<"\n";
       double s =0;
        
        for(int i=0;i<n;i++){
            
          if(get<1>(v[n-1-i])<=c){
                
                
                //cout<<get<2>(v[n-1-i])<<endl;
                s+=(double)get<2>(v[n-1-i]);
                
                
                c=c-get<1>(v[n-1-i]);
             
            }
            else if(c!=0  && get<1>(v[n-1-i])>c){
                
                
                s+=get<0>(v[i])*(double)c;
                
                break;
            }
           
         //cout<<s<<endl;
            
        }
        //cout<<s<<endl;
        cout<<(int)round(s)<<endl;
        
        
    }
    
    
}