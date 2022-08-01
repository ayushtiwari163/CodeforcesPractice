#include <iostream>
using namespace std;
int find_max_index(int left, int right, int* A)
{
    if((right - left) < 1)
    {
        return left;
    }
    else
    {
        int mid = (left + right)/2;
        if(A[mid] >= A[mid - 1])
        {
            return find_max_index(mid,right,A);
        }
        else
        {
            return find_max_index(left,mid,A);
        }
    }
}
int main ()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int marks[N];
        for(int i = 0; i < N; i++)
        {
            cin>>marks[i];
        }
        int freq[101]={0};
        for(int j = 0; j < N; j++)
        {
            freq[marks[j]]++;
        }
        string s="";
        string s1="";
        for(int p = 0; p < 101; p++)
        {
            // cout<<freq[p]<<" ";
            s=s+(char)(freq[p]+'0');

        }
        int r = 0;
        for(int k = 0; k < 101; k++)
        {
            if(freq[k] != 0)
            {
                r++;
            }
        }
        int real_freq[r], h = 0;
        for(int y = 0; y < 101; y++)
        {
            if(freq[y] != 0)
            {
                real_freq[h] = freq[y];
                h++;
            }
            +
        }
        cout<<"\n";
        
        for(int p = 0; p < 101; p++)
        {
          //  cout<<freq[p]<<" ";
            s1=s1+(char)(freq[p]+'0');
        }
        cout<<s1<<endl;
        cout<<s<<endl;
        if(s1==s)
        cout<<"T";
        else 
        cout<<"N";
        // for(int p = 0; p < r; p++)
        // {
        //     cout<<real_freq[p]<<" ";
        // }
        cout<<"\n";
        //int ans = find_max_index(0,r-1,real_freq);
        //cout<<ans;
    }
    return 0;
}