//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int i, int tranNo, int prices[], int n, int k, vector<vector<int>> &dp)
    {
        if(i==n || tranNo==2*k)
            return 0;
        if(dp[i][tranNo]!=-1)
            return dp[i][tranNo];
        if(tranNo%2==0)
        {
            return dp[i][tranNo] = max(solve(i+1, tranNo, prices, n, k, dp), solve(i+1, tranNo+1, prices, n, k, dp)-prices[i]);
        }
        else
        {
            return dp[i][tranNo] = max(solve(i+1, tranNo, prices, n, k, dp), solve(i+1, tranNo+1, prices, n, k, dp)+prices[i]);
        }
    }
    int maxProfit(int k, int n, int prices[]) {
        // code here
        vector<vector<int>> dp(n, vector<int>(2*k,-1));
        return solve(0, 0, prices, n, k, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends