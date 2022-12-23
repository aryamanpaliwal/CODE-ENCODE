//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&arr ,int d) {
        //Your code here
        int n=arr.size();
        int sum=0;
        for(auto x:arr)
            sum+=x;
        if((sum+d)%2==1 || sum<d)
            return 0;
        if(n==1)
        {
            if(arr[0]==d || arr[0]==-1*d)
                return 1;
            return 0;
        }
        sum=(sum+d)/2;
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=sum;j++) {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=sum;j++) {
                if(j>=arr[i-1])
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends