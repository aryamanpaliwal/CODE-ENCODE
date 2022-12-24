//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
	    int x=s1.length();
	    int y=s2.length();
	    int dp[x+1][y+1];
	    for(int i=0;i<=x;i++) {
	        for(int j=0;j<=y;j++) {
	            if(i==0 || j==0)
	                dp[i][j]=0;
	        }
	    }
	    for(int i=1;i<=x;i++) {
	        for(int j=1;j<=y;j++) {
	            if(s1[i-1]==s2[j-1])
	                dp[i][j]=1+dp[i-1][j-1];
	            else
	                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    int del=x-dp[x][y];
	    int ins=y-dp[x][y];
	    return del+ins;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends