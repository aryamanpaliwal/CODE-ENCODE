//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        int dp[n+1][3];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int act=0;act<3;act++)
            {
                int act1=0, act2=0, act0=0;
                if(act!=0)
                {
                    act0 = dp[i-1][0]+points[i-1][0];
                }
                if(act!=1)
                {
                    act1 = dp[i-1][1]+points[i-1][1];
                }
                if(act!=2)
                {
                    act2 = dp[i-1][2]+points[i-1][2];
                }
                dp[i][act]=max({act1, act2, act0});
            }
        }
        return max(dp[n][0], max(dp[n][1], dp[n][2]));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends