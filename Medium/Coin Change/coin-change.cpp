//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int a[], int n, int s) {

        // code here.
        long long int dp[n+1][s+1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=s;j++) {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=s;j++) {
                if(j>=a[i-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-a[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][s];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends