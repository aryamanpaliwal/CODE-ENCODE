//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(string s1, string s2)
    {
        // if(s1.length()+1!=s2.length())
        // {
        //     return false;
        // }
        int j=0;
        bool flag=false;
        for(int i=0;i<s2.length() && j<s1.length();i++)
        {
            if(s2[i]==s1[j])
            {
                j++;
            }
            else
            {
                if(!flag)
                    flag=true;
                else
                    return false;
            }
        }
        return true;
    }
    static bool mycmp(string &a, string &b)
    {
        return (a.length()<b.length());
    }
    int longestChain(int n, vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), mycmp);
        vector<int> dp(n,1);
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(words[j].length()+1==words[i].length() && check(words[j], words[i]))
                {
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
            res=max(res, dp[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends