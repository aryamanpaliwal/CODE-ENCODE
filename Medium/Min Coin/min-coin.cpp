//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>a, int s)
	{
	    // Code here
	    int n=a.size();
	    int dp[n+1][s+1];
	    for (int i=0;i<=n;i++) {
	        for (int j=0;j<=s;j++) {
	            if(j==0)
	                dp[i][j]=0;
	            if(i==0)
	                dp[i][j]=INT_MAX-1;
	        }
	    }
	    for(int i=1;i<=n;i++) {
	        for(int j=1;j<=s;j++) {
	            if(j>=a[i-1])
	                dp[i][j]=min(dp[i-1][j], 1+dp[i][j-a[i-1]]);
	            else
	                dp[i][j]=dp[i-1][j];
	        }
	    }
	    if(dp[n][s]==INT_MAX-1)
	        return -1;
	    return dp[n][s];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends