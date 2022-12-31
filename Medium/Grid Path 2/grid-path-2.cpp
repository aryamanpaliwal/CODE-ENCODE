//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dp[101][101];
    int mod=1e9+7;
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        if(i>m || j>n || grid[i][j]==1)
            return 0;
        if(i==m && j==n)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j]%mod;
        return dp[i][j] = (solve(i+1,j,m,n,grid)%mod + solve(i, j+1, m, n, grid)%mod)%mod;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        memset(dp, -1, sizeof(dp));
        return solve(0,0,n-1, m-1, grid)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends