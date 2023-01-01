//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int i, int buy, vector<long long> &prices, int n, vector<vector<long long>> &dp, int fee)
    {
        if(i>=n)
            return 0;
        int res=0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy)
        {
            res = max(solve(i+1, 1, prices, n, dp, fee), solve(i+1, 0, prices, n, dp, fee)-prices[i]);
        }
        else
        {
            res = max(solve(i+1, 0, prices, n, dp, fee), prices[i] - fee + solve(i+1, 1, prices, n, dp, fee));
        }
        return dp[i][buy] = res;
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, 1, prices, n, dp, fee);
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
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends