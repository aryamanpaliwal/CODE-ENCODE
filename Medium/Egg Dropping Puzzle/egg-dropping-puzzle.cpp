//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int myfun(int e, int f)
    {
        if(e==1)
            return f;
        if(f==1 || f==0)
            return f;
        if(dp[e][f]!=-1)
            return dp[e][f];
        int res=INT_MAX;
        for(int i=1;i<=f;i++)
        {
            int temp = 1 + max(myfun(e-1, i-1), myfun(e, f-i));
            res=min(res, temp);
        }
        return dp[e][f] = res;
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        memset(dp, -1, sizeof(dp));
        return myfun(e,f);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends