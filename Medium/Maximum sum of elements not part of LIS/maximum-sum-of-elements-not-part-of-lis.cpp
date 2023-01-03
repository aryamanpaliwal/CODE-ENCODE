//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSumLis(int a[], int n) {
        // code here
        vector<int> dp(n, 1);
        vector<int> prev(n);
        prev[0]=0;
        int mi=0;
        int sum=a[0];
        for(int i=1;i<n;i++)
        {
            sum+=a[i];
            prev[i]=i;
            for(int j=0;j<i;j++)
            {
                if(a[i]>a[j] && dp[j]+1>=dp[i])
                {
                    if(dp[i]==dp[j]+1)
                    {
                        if(a[prev[i]==a[j]])
                        {
                            if(prev[i]<j)
                                prev[i]=j;
                        }
                        else if(a[prev[i]]>a[j])
                            prev[i]=j;
                    }
                    else
                        prev[i]=j;
                    dp[i]=dp[j]+1;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            if(dp[i]>=dp[mi])
                mi=i;
        }
        // for(auto x:dp)
        //     cout<<x<<" ";
        // cout<<endl;
        // vector<int> res;
        int lis_sum=0;
        int li=mi;
        // cout<<mi<<endl;
        while(prev[li]!=li)
        {
            // res.push_back(a[li]);
            lis_sum+=a[li];
            li=prev[li];
        }
        // res.push_back(a[li]);
        // reverse(res.begin(), res.end());
        // for(auto x:res)
        //     cout<<x<<" ";
        // cout<<endl;
        lis_sum+=a[li];
        return sum-lis_sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int Arr[n];
        for (int i = 0; i < n; i++) cin >> Arr[i];
        Solution obj;
        cout << obj.maxSumLis(Arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends