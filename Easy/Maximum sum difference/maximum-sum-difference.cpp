//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxSum(int n){
        // code here
        if(n==1)
            return 1;
        return ((n-1)*(n+1)-1)/2;
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
        cout<<ob.maxSum(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends