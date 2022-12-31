//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int dp[16][16];
    int solve(int i, int j, int m, int n)
    {
        if(i>m || j>n)
            return 0;
        if(i==m && j==n)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = solve(i+1,j,m,n) + solve(i, j+1, m, n);
        
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        memset(dp, -1, sizeof(dp));
        return solve(0,0,a-1,b-1);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends