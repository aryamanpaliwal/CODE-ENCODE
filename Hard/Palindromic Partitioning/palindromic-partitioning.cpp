//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    bool isPal(string &s, int l, int h)
    {
        if(l>=h)
            return true;
        while(l<h)
        {
            if(s[l]!=s[h])
                return false;
            l++;
            h--;
        }
        return true;
        
    }
    int myfun(string &s, int l, int h){
        if(l>=h)
            return 0;
        if(dp[l][h]!=-1)
            return dp[l][h];
        if(isPal(s, l, h))
            return 0;
        int res=INT_MAX;
        for(int i=l; i<h;i++)
        {
            res = min( res, myfun(s, l, i) + myfun(s, i+1, h) + 1);
        }
        return dp[l][h] = res;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        memset(dp, -1, sizeof(dp));
        return myfun(str, 0, n-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends