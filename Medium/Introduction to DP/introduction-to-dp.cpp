//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int dp[100001];
class Solution {
  public:
    long long int mod = 1000000007;
    long long int topDown(int n) {
        // code here
        if(n==0 || n==1)
            return n;
        if(dp[n]!=-1)
            return dp[n]%mod;
        return dp[n] = (topDown(n-1) + topDown(n-2))%mod;
    }
    long long int bottomUp(int n) {
        // code here
        long long int a[n+1];
        if(n==0 || n==1)
            return n;
        a[0]=0;
        a[1]=1;
        for(int i=2;i<=n;i++)
        {
            a[i]=(a[i-1]+a[i-2])%mod;
        }
        return a[n]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100001; i++) dp[i] = -1;
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends