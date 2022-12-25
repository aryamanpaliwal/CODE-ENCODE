//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    map<pair<pair<int,int>,bool>, int> mp;
    int myfun(string s, int l, int h, bool to_eval)
    {
        if(l>h)
            return false;
        if(mp.find({{l,h},to_eval})!=mp.end())
            return mp[{{l,h},to_eval}];
        if(l==h)
        {
            if(to_eval)
                return s[l]=='T';
            if(!to_eval)
                return s[l]=='F';
        }
        int res=0;
        for(int i=l+1;i<=h-1;i+=2)
        {
            int lt=myfun(s, l, i-1, true);
            int lf=myfun(s, l, i-1, false);
            int rt=myfun(s, i+1, h, true);
            int rf=myfun(s, i+1, h, false);
            if(s[i]=='&')
            {
                if(to_eval)
                    res += (lt*rt);
                else
                    res+= (lf*rt + lf*rf + lt*rf);
            }
            else if(s[i]=='|')
            {
                if(to_eval)
                    res+= (lf*rt + lt*rt + lt*rf);
                else
                    res += (lf*rf);
            }
            else if(s[i]=='^')
            {
                if(to_eval)
                    res += (lt*rf + lf*rt);
                else
                    res+= (lf*rf + lt*rt);
            }
        }
        int m=1003;
        return mp[{{l,h},to_eval}] = res%m;
        // return res;
    }
    int countWays(int n, string s){
        // code here
        // memset(dp, -1, sizeof(dp));
        return myfun(s, 0, n-1, true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends