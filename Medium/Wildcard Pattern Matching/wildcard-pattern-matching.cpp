//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pat,string str)
    {
        int n=str.length();
        int m=pat.length();
        bool dp[n+1][m+1];
        dp[0][0]=true;
        for(int i=1;i<=n;i++)
            dp[i][0]=false;
        for(int i=1;i<=m;i++)
        {
            if(pat[i-1]=='*')
                dp[0][i]=dp[0][i-1];
            else
                dp[0][i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(pat[j-1]==str[i-1] || pat[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(pat[j-1]=='*')
                    dp[i][j]=dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends