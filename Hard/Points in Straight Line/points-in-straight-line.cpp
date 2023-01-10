//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
public:
    int maxPoints(int X[], int Y[], int n)
    {
       //code here
       int res=0;
       for(int i=0;i<n;i++)
       {
           unordered_map<double, int> mp;
           for(int j=0;j<n;j++)
           {
               if(i!=j)
               {
                   double x1=X[i], y1=Y[i];
                   double x2=X[j], y2=Y[j];
                   double slope;
                   if(x2-x1!=0)
                    slope=((y2-y1)/(x2-x1));
                   else
                    slope=INT_MAX;
                   mp[slope]++;
               }
           }
           for(auto m:mp)
            res=max(res, m.second);
       }
       return res+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n], y[n];
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<n;i++){
            cin>>y[i];
        }
        Solution ob;
        cout << ob.maxPoints(x, y, n) << endl;
    }
    return 0;
}

// } Driver Code Ends