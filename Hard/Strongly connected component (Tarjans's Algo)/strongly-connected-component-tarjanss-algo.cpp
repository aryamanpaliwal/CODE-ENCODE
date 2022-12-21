//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs(vector<int> &disc, vector<int> &low, vector<bool> &vis, stack<int> &st, vector<vector<int>> &res, int &timer, vector<int> adj[], int node)
    {
        disc[node]=low[node]=timer++;
        st.push(node);
        vis[node]=true;
        
        for(auto x:adj[node])
        {
            if(disc[x]==-1)
            {
                dfs(disc, low, vis, st, res, timer, adj, x);
                low[node]=min(low[node], low[x]);
            }
            else if(vis[x]==true)
            {
                low[node]=min(disc[x], low[node]);
            }
        }
        
        if(low[node]==disc[node])
        {
            vector<int> temp;
            
            while(st.top()!=node)
            {
                vis[st.top()]=false;
                temp.push_back(st.top());
                st.pop();
            }
            if(st.empty()==false)
            {
                vis[st.top()]=false;
                temp.push_back(st.top());
                st.pop();
            }
            sort(temp.begin(), temp.end());
            res.push_back(temp);
        }
    }
    vector<vector<int>> tarjans(int v, vector<int> adj[])
    {
        //code here
        vector<int> disc(v, -1);
        vector<int> low(v, -1);
        int timer=0;
        vector<bool> vis(v, false);
        stack<int> st;
        vector<vector<int>> res;
        for(int i=0;i<v;i++)
        {
            if(disc[i]==-1)
            {
                dfs(disc, low, vis, st, res, timer, adj, i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends