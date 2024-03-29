//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> temp[]) {
        // code here
        vector<int> adj[V];
        vector<int> in(V,0);
        queue<int> q;
        for(int i=0;i<V;i++) {
            for(auto x:temp[i]) {
                adj[x].push_back(i);
                in[i]++;
            }
            if(in[i]==0) {
                q.push(i);
            }
        }
        vector<int> res;
        while(q.empty()==0) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto x:adj[curr]) {
                in[x]--;
                if(in[x]==0) {
                    q.push(x);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends