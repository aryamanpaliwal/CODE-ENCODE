//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int dp[10002];
    int mod=1000000007;
    int solve(int n) {
        if(dp[n]!=-1)
            return dp[n]%mod;
        if(dp[n-1]==-1)
            dp[n-1]=solve(n-1)%mod;
        if(dp[n-2]==-1)
            dp[n-2]=solve(n-2)%mod;
        return dp[n] = (dp[n-1]+dp[n-2])%mod;
    }
    int countWays(int n)
    {
        // your code here
        memset(dp, -1, sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        return solve(n);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends