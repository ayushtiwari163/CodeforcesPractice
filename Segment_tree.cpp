#include <bits/stdc++.h>
using namespace std;  
class Segment_Tree
{
      vector<int> seg;
      vector<int> array;
      public:
      Segment_Tree(int size, vector<int> arr)
      {
            int x =  4;
            int n= x*size+1;
            seg.resize(n+1,0);
            array = arr;
      }
      int construct_tree(int start,int l, int r)
      {
          if(l==r)
          {
              seg[start]=array[l];
              return array[l];
          }
          int mid = (l+r)/2;
          seg[start] = max(construct_tree(2*start+1,l,mid),construct_tree(2*start+2,mid+1,r));
          return seg[start]; 
      }
      int get_max(int index,int start,int end, int l, int r)
      {
          if(l<=start && r>=end)
          return seg[index];
          if(end<l || start>r)
          return 0;
          int mid = (start+end)/2;
          return max(get_max(2*index+1,start,mid,l,r) , get_max(2*index+2,mid+1,end,l,r));

      }
     
        

};
int main() {
int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++)
cin>>a[i];
Segment_Tree segm(n,a);
segm.construct_tree(0,0,n-1);
int u,v;
cin>>u>>v;
cout<<segm.get_max(0,0,n-1,u,v)<<' ';
//segm.update(0,0,n-1,1,4);
cout<<segm.get_max(0,0,n-1,0,0);

}