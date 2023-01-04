//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string check(string x, string res)
    {
        if(x.length()>res.length())
            return x;
        else if(x.length()<res.length())
            return res;
        if(x.compare(res)<0)
            return x;
        return res;
    }
    string longestString(vector<string> &words)
    {
        // code here
        set<string> s;
        for(auto x:words)
            s.insert(x);
        string res="";
        for(auto x:words)
        {
            int n=x.length();
            int i;
            for(i=0;i<n-1;i++)
            {
                if(s.find(x.substr(0, i+1)) == s.end())
                    break;
            }
            if(i==n-1)
                res=check(x, res);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends