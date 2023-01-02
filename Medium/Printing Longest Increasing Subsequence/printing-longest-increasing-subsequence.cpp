//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& a) {
        // Code here
        set<int> s;
        for(auto x:a)
            s.insert(x);
        vector<int> temp;
        for(auto x:s)
            temp.push_back(x);
        // int n=a.size();
        int m=temp.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==temp[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        vector<int> res;
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(a[i-1]==temp[j-1])
            {
                res.push_back(a[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]<dp[i][j-1])
                    j--;
                else
                    i--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends