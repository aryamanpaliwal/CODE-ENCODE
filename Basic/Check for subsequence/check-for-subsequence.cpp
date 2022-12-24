//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    public:
    bool isSubSequence(string s, string t) 
    {
        // code here
        int sl=s.length();
        int tl=t.length();
        while(sl>0 && tl>0)
        {
            if(t[tl-1]==s[sl-1])
            {
                tl--;
                sl--;
            }
            else
                tl--;
        }
        if(sl==0)
            return true;
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 

// } Driver Code Ends