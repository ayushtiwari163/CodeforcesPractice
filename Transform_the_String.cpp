#include <iostream>

using namespace std;

//function to check whether the rat can move in the desired box.

bool isSafe(int** arr, int x, int y, int n){
    if(x<n && y<n && arr[x][y] == 1){
        return true;
    }return false;
}


bool ratInMaze(int** arr, int x, int y, int n, int** solArr){
    
    //base condition that rat has reached the destination.

    if(x==n-1 && y==n-1){
        solArr[x][y]=1;
        return true;
    }
    
    //if the rat has the valid path to move

    if(isSafe(arr, x, y, n)){
        solArr[x][y]=1;
        
        //if the rat has a valid path in the forward direction.

        if(ratInMaze(arr, x+1, y, n, solArr)){
            return true;
        }
        
        //if the rat has a valid path in the downward direction.

        if(ratInMaze(arr, x, y+1, n, solArr)){
            return true;
        }
        
        //if no valid path, then backtrack

        solArr[x][y]=0;
        return false;
    }
    //if by no means rat can reach the destination.
    return false;
}

int main()
{
    int n;
    cin>>n;
    
    //dynamically allocated array.
    
    int** arr=new int*[n];
    for(int i=0; i<n; i++){
        arr[i]=new int[n];
    }
    
    //initialising array.
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    
    //initialising solution array and finding the answer.
    
    int** solArr = new int* [n];
    for(int i=0; i<n; i++){
        solArr[i]=new int[n];
        for(int j=0; j<n; j++){
            solArr[i][j]=0;
        }
    }
ratInMaze(arr,0,0,n,solArr);
// print the output grid
    for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
         cout<<solArr[i][j]<<" ";
     cout<<endl;
    }  
}
