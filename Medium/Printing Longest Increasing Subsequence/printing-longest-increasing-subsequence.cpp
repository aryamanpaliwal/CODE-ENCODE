//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& a) {
        vector<pair<int, int>> dp(n);
        vector<int> prev(n);
        for(int i=0;i<n;i++)
        {
            dp[i]={a[i],1};
            prev[i]=i;
        }
        int mi=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j]<a[i] && dp[i].second<1+dp[j].second)
                {
                    dp[i].second=1+dp[j].second;
                    prev[i]=j;
                }
            }
            if(dp[i].second>dp[mi].second)
            {
                mi=i;
            }
        }
        int li=mi;
        vector<int> res;
        while(prev[li]!=li)
        {
            res.push_back(a[li]);
            li=prev[li];
        }
        res.push_back(a[li]);
        reverse(res.begin(), res.end());
        return res;
        
        // Code here
        // set<int> s;
        // for(auto x:a)
        //     s.insert(x);
        // vector<int> temp;
        // for(auto x:s)
        //     temp.push_back(x);
        // // int n=a.size();
        // int m=temp.size();
        // int dp[n+1][m+1];
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         if(i==0 || j==0)
        //             dp[i][j]=0;
        //     }
        // }
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //     {
        //         if(a[i-1]==temp[j-1])
        //             dp[i][j]=1+dp[i-1][j-1];
        //         else
        //             dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        //     }
        // }
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        // vector<int> res;
        // int i=n,j=m;
        // while(i>0 && j>0)
        // {
        //     if(a[i-1]==temp[j-1])
        //     {
        //         res.push_back(a[i-1]);
        //         i--;
        //         j--;
        //     }
        //     else
        //     {
        //         if(dp[i-1][j]<dp[i][j-1])
        //             j--;
        //         else
        //             i--;
        //     }
        // }
        // reverse(res.begin(), res.end());
        // return res;
        
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