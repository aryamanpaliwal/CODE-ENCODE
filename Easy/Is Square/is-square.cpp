//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dist(int x1, int y1, int x2, int y2)
    {
        return (pow(x2-x1, 2)+ pow(y2-y1, 2));
    }
    string isSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        // code here
        unordered_set<int> s;
        s.insert(dist(x1,y1, x2,y2));
        s.insert(dist(x1,y1, x3,y3));
        s.insert(dist(x1,y1, x4,y4));
        s.insert(dist(x3,y3, x2,y2));
        s.insert(dist(x4,y4, x2,y2));
        s.insert(dist(x3,y3, x4,y4));
        if(s.size()==2 && s.find(0)==s.end())
            return "Yes";
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

        Solution ob;
        cout << ob.isSquare(x1,y1,x2,y2,x3,y3,x4,y4) << endl;
    }
    return 0;
}
// } Driver Code Ends