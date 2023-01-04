//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j] && dp[j]+1>=dp[i])
                {
                    if(dp[i]==dp[j]+1)
                    {
                        count[i]+=count[j];
                    }
                    else
                    {
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                }
            }
            maxi=max(maxi, dp[i]);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
                res+=count[i];
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends