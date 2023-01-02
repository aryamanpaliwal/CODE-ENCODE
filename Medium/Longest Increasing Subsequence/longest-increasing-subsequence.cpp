//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int i, int last, int a[], int n, vector<vector<int>> &dp)
    {
        if(i==n)
            return 0;
        if(dp[i][last]!=-1)
            return dp[i][last];
        if(a[i]+1>last)
        {
            return dp[i][last]=max(1+solve(i+1, a[i]+1, a, n, dp), solve(i+1, last, a, n, dp));
        }
        return dp[i][last]=solve(i+1, last, a, n, dp);
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
        int maxi=*max_element(a, a + n);
        vector<vector<int>> dp(n+1, vector<int> (maxi+2, -1));
        return solve(0, 0, a, n, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends