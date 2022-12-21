//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(vector<int> adj[], int v, vector<bool> &vis, int node, int curr_count)
    {
        vis[node]=true;
        curr_count++;
        if(curr_count==v)
        {
            return true;
        }
        for(auto x:adj[node])
        {
            if(vis[x]==false && dfs(adj, v, vis, x, curr_count))
                return true;
        }
        vis[node]=false;
        curr_count--;
        return false;
    }
    bool check(int v,int e,vector<vector<int>> edges)
    {
        // code here
        vector<int> adj[v];
        for(int i=0;i<e;i++)
        {
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(v, false);
        for(int i=0;i<v;i++)
        {
            if(vis[i]==false && dfs(adj, v, vis, i, 0))
                return true;
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends