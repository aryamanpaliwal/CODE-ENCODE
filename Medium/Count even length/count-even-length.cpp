//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	int mod=1e9+7;
	public:
    long long inverse(long long n)
	{
	    long long temp=n;
	    n=mod-2;
	    long long temp2=1;
	    while(n>0)
	    {
	        if(n&1)
	        {
	            temp2*=temp;
	            temp2%=mod;
	        }
	        n/=2;
	        temp*=temp;
	        temp%=mod;
	    }
	    temp2%=mod;
	    return temp2;
	}
	int compute_value(int n)
	{
	    // Code here
	    long long facn=1;
	    long long fac2n=1;
	    for(int i=1;i<=2*n;i++)
	    {
	        fac2n*=i;
	        fac2n%=mod;
	        if(i==n)
	            facn=fac2n;
	    }
	    facn=(facn*facn)%mod;
	    long long tmep=inverse(facn);
	    long long res=((fac2n%mod)*(tmep%mod))%mod;
	    return int(res);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends