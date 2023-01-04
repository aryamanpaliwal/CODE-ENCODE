//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int a[], int n) {
        // code here
        vector<int> dp;
        dp.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            auto it=lower_bound(dp.begin(), dp.end(), a[i]);
            if(it==dp.end())
                dp.push_back(a[i]);
            else
                dp[it-dp.begin()]=a[i];
        }
        return n-dp.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends