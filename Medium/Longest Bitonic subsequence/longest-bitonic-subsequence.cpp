//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> lis(vector<int> a)
	{
	    int n=a.size();
	    vector<int> dp(n, 1);
	    for(int i=1;i<n;i++)
	    {
	        for(int j=0;j<i;j++)
	        {
	            if(a[i]>a[j])
	                dp[i]=max(dp[i], 1+dp[j]);
	        }
	    }
	    return dp;
	}
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    vector<int> v1=lis(nums);
	    reverse(nums.begin(), nums.end());
	    vector<int> v2=lis(nums);
	    reverse(nums.begin(), nums.end());
	   // for(auto x:v1)
	   //     cout<<x<<" ";
	   // cout<<endl;
	    reverse(v2.begin(), v2.end());
	   // for(auto x:v2)
	   //     cout<<x<<" ";
	   // cout<<endl;
	    int res=INT_MIN;
	    for(int i=0;i<nums.size()-1;i++)
	    {
	        for(int j=i+1;j<nums.size();j++)
	        {
	            if(nums[i]==nums[j])
	            {
	               // cout<<nums[i]<<" "<<nums[j]<<endl;
	               // cout<<v1[i]<<" "<<v2[j]<<endl;
	                res=max(res, v1[i]+v2[j]-1);
	               // cout<<res<<endl;
	            }
	            else
	            {
	               // cout<<nums[i]<<" "<<nums[j]<<endl;
	               // cout<<v1[i]<<" "<<v2[j]<<endl;
	                res=max(res, v1[i]+v2[j]);
	               // cout<<res<<endl;
	            }
	        }
	    }
	    if(res==INT_MIN)
	        return 1;
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends