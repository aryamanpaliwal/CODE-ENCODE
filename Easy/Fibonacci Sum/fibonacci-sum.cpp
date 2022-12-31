//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    long long int fibSum(long long int n){
        //code here
        if(n<=1)
            return n;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        long long int sum=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=(dp[i-1]%1000000007+dp[i-2]%1000000007)%1000000007;
            sum+=dp[i];
            sum%=1000000007;
        }
        return sum%1000000007;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends