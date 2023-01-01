//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myfun(int r, int cr1, int cr2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if(cr1<0 || cr2<0 || cr1>=m || cr2>=m)
        {
            return -1*(1e9+7);
        }
        if(dp[r][cr1][cr2]!=-1)
            return dp[r][cr1][cr2];
        if(r==n-1)
        {
            if(cr1==cr2)
                return grid[r][cr1];
            return grid[r][cr1]+grid[r][cr2];
        }
        int res=INT_MIN;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(cr1==cr2)
                    res=max(res, grid[r][cr1]+myfun(r+1, cr1+i, cr2+j, n, m, grid, dp));
                else
                    res=max(res, grid[r][cr1]+grid[r][cr2]+myfun(r+1, cr1+i, cr2+j, n, m, grid, dp));
            }
        }
        return dp[r][cr1][cr2]=res;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return myfun(0, 0, m-1, n, m, grid, dp);
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends