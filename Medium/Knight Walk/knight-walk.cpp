//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&pos, vector<int>&tpos, int n){
	    // Code here
	    if(pos[0]==tpos[0] && pos[1]==tpos[1])
	        return 0;
	    queue<pair<int, int>> q;
	    q.push({pos[0],pos[1]});
	    vector<pair<int,int>> dirs({{1,-2},{-1,-2},{-2,-1},{+2,-1},{-2,1},{2,1},{-1,2},{1,2}});
	    vector<vector<int>> vis(n+1,vector<int>(n+1,INT_MAX));
	    vis[pos[0]][pos[1]]=0;
	    while(q.empty()==false)
	    {
	        int r=q.front().first;
	        int c=q.front().second;
	        q.pop();
	       // cout<<vis[r][c];
	        for(auto x:dirs)
	        {
	            int ri=r+x.first;
	            int ci=c+x.second;
	            if(ri>0 && ri<=n && ci>0 && ci<=n && vis[ri][ci]>1+vis[r][c])
	            {
	                vis[ri][ci]=1+vis[r][c];
	                if(ri==tpos[0] && ci==tpos[1])
	                    return vis[ri][ci];
	                q.push({ri,ci});
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends