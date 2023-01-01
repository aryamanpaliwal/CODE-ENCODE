//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int i, int buy, vector<long long> &prices, int n, vector<vector<long long>> &dp)
    {
        if(i>=n)
            return 0;
        int res=0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy)
        {
            res = max(solve(i+1, 1, prices, n, dp), solve(i+1, 0, prices, n, dp)-prices[i]);
        }
        else
        {
            res = max(solve(i+1, 0, prices, n, dp), prices[i] + solve(i+2, 1, prices, n, dp));
        }
        return dp[i][buy] = res;
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, 1, prices, n, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends