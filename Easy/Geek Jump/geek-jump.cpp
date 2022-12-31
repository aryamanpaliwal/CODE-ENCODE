//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> a(n, INT_MAX);
        a[0]=0;
        for(int i=0;i<n;i++)
        {
            if(i+1<n)
            {
                a[i+1] = min(a[i+1], a[i] + abs(height[i]-height[i+1]));
            }
            if(i+2<n)
            {
                a[i+2] = min(a[i+2], a[i] + abs(height[i]-height[i+2]));
            }
        }
        return a[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends