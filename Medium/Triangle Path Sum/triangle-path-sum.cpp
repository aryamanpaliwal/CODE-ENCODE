//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int r, int c, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if(r==triangle.size()-1)
            return triangle[triangle.size()-1][c];
        if(dp[r][c]!=-1)
            return dp[r][c];
        return dp[r][c]=min(triangle[r][c]+solve(r+1, c, triangle, dp), triangle[r][c]+solve(r+1, c+1, triangle, dp));
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0,0,triangle,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends