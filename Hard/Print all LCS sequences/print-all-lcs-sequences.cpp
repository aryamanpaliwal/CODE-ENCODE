//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	   	set<string>st;
        void myfun(string s1,string s2,int i,int j,string &temp,vector<string>&ans,int count){
           
           if(count==0)
	       {
	           if(st.find(temp)==st.end())
	           {
	               st.insert(temp);
	               ans.push_back(temp);
	           }
	           return;
	       }
           if(i>=s1.size() || j>=s2.size())
	       {
	           return;
	       }
        
           for(int x=i; x<s1.size();x++)
	       {
	           for(int y=j; y<s2.size();y++)
	           {
	               if(s1[x]==s2[y])
	               {
	                   temp.push_back(s1[x]);
	                   myfun(s1, s2, x+1, y+1, temp, ans, count-1);
	                   temp.pop_back();
	               }
	           }
	       }
        }
		vector<string> all_longest_common_subsequences(string s1, string s2)
		{
		    // Code here
		    int x=s1.length();
		    int y=s2.length();
		    int dp[x+1][y+1];
		    for(int i=0;i<=x;i++) {
		        for(int j=0;j<=y;j++) {
		            if(i==0 || j==0)
		                dp[i][j]=0;
		            else if(s1[i-1]==s2[j-1])
		                dp[i][j]=1+dp[i-1][j-1];
		            else
		                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		        }
		    }
		    vector<string> ans;
		    string temp="";
		    myfun(s1,s2,0,0,temp,ans,dp[x][y]);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends