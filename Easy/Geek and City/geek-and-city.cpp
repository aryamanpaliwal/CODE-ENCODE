//? AUTHOR : ARYAMAN PALIWAL
//? ID : 2020KUCP1005
//? MAILTO : 2020kucp1005@iiitkota.ac.in

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lli long long int
#define fora(n) for (lli i = 0; i < n; i++)
#define fora1(n) for (lli j = 0; j < n; j++)
#define fora_(n) for (lli i = n - 1; i >= 0; i--)
#define forn(n) for (lli i = 1; i <= n; i++)
#define forr(a, b, c) for (lli i = a; i < b; i = i + c)
#define forr_(a, b, c) for (lli i = a; i >= b; i = i - c)
using namespace std;
void solve(int i, vector<int> adj[], vector<bool> &vis)
{
    vis[i]=true;
    for(auto x:adj[i])
    {
        if(vis[x]==false)
        {
            solve(x,adj,vis);
        }
    }
}

int main()
{
    FASTIO
    lli __;
    cin >> __;
    while (__--)
    {
        lli n,m;
        cin>>n>>m;
        vector<int> adj[n+1];
        fora(m)
        {
            lli u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n+1, false);
        int count=-1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
                count++;
                solve(i, adj, vis);
            }
        }
        cout<<count<<endl;
    }
    return 0;
}