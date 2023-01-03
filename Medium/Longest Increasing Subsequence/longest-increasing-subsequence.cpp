//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int i, int last, int a[], int n, vector<vector<int>> &dp)
    {
        if(i==n)
            return 0;
        if(dp[i][last]!=-1)
            return dp[i][last];
        if(a[i]+1>last)
        {
            return dp[i][last]=max(1+solve(i+1, a[i]+1, a, n, dp), solve(i+1, last, a, n, dp));
        }
        return dp[i][last]=solve(i+1, last, a, n, dp);
    }
    int longestSubsequence(int n, int a[])
    {
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i]={a[i], 1};
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[j].first<v[i].first)
                {
                    v[i].second=max(v[i].second, v[j].second+1);
                }
            }
        }
        int res=INT_MIN;
        for(auto x:v)
        {
            // cout<<x.second<<" ";
            res=max(res, x.second);
        }
        return res;
        
        
        
        
       // your code here
        // int maxi=*max_element(a, a + n);
        // vector<vector<int>> dp(n+1, vector<int> (maxi+2, -1));
        // return solve(0, 0, a, n, dp);
        // set<int> s;
        // for(int i=0;i<n;i++)
        //     s.insert(a[i]);
        // vector<int> temp;
        // for(auto x:s)
        //     temp.push_back(x);
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
        // return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends