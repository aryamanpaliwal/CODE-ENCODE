//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void myfun(vector<int> a, vector<int> &res, int s)
    {
        if(s<=0)
            return;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]<=s)
            {
                res.push_back(a[i]);
                return myfun(a, res, s-a[i]);
            }
        }
    }
    vector<int> minPartition(int s)
    {
        // code here
        vector<int> a({ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000});
        reverse(a.begin(), a.end());
        vector<int> res;
        myfun(a, res, s);
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends