//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int dp[100][100];
    int myfun(int arr[], int l, int h)
    {
        if(l>=h)
            return 0;
        if(dp[l][h]!=-1)
            return dp[l][h];
        int res=INT_MAX;
        for(int i=l;i<=h-1;i++)
        {
            int temp = myfun(arr, l, i) + myfun(arr, i+1, h) + arr[l-1]*arr[i]*arr[h];
            res=min(res, temp);
        }
        
        return dp[l][h] = res;
    }
public:
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return myfun(arr, 1, N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends