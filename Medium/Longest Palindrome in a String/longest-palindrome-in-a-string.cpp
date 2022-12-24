//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string str) {
        // code here
        string res="";
        int curr_len=0;
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0 && r<n && str[l]==str[r])
            {
                if((r-l+1)>curr_len)
                {
                    curr_len=r-l+1;
                    res=str.substr(l,curr_len);
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && str[l]==str[r])
            {
                if((r-l+1)>curr_len)
                {
                    curr_len=r-l+1;
                    res=str.substr(l, curr_len);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends