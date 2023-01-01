//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int isGoodorBad(string s) {
        // code here
        int vc=0;
        int cc=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                vc++;
                cc=0;
            }
            else if(s[i]=='?')
            {
                if(vc==0)
                {
                    cc++;
                }
                else
                {
                    vc++;
                }
            }
            else
            {
                cc++;
                vc=0;
            }
            if(cc>3 || vc>5)
                return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        
        cin >> S;
        
        Solution ob;
        cout << ob.isGoodorBad(S) << endl;
    }
    return 0; 
}
// } Driver Code Ends