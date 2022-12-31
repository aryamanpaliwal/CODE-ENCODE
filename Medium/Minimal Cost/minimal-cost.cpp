//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> v(n, INT_MAX);
        v[0]=0;
        for(int i=0;i<n;i++)
        {
            int j=k;
            while(j--)
            {
                if(i+j+1<n)
                {
                    v[i+j+1] = min(v[i+j+1], v[i] + abs(height[i]-height[i+j+1]));
                }
            }
        }
        return v[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends