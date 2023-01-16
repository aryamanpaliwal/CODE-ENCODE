//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int num, int den)
	{
	    // Code here
	    string res="";
	    long long q=num/den;
	    res+=to_string(q);
	    long long rem=num%den;
	    if(rem==0)
	        return res;
	    res+=".";
	    unordered_map<long long,int> mp;
	    while(rem!=0)
	    {
	        if(mp.find(rem)!=mp.end())
	        {
	            int pos=mp[rem];
	            res.insert(pos,"(");
	            res+=")";
	            break;
	        }
	        else
	        {
	            mp[rem]=res.length();
	            rem*=10;
	            q=rem/den;
	            rem%=den;
	            res+=to_string(q);
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends