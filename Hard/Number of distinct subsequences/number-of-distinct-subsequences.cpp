//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int m=1000000007;
	    int n=s.length();
	    int dp[n+1];
	    dp[0]=1;
	    vector<int> vis(26, -1);
	    for(int i=0;i<n;i++)
	    {
	        int ch=s[i]-'a';
	        dp[i+1]=dp[i]*2%m;
	        if(vis[ch]>-1)
	            dp[i+1]-=dp[vis[ch]];
	        dp[i+1]%=m;
	        vis[ch]=i;
	    }
	   // dp[n]--;
	    if(dp[n]<0)
	        dp[n]+=m;
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends