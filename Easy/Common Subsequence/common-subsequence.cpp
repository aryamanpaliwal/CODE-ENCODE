//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	bool commonSubseq (string s1, string s2)
	{
	    // your code here
	    int x=s1.length();
	    int y=s2.length();
		for(int i=0;i<x;i++)
		{
		    for(int j=0;j<y;j++)
		    {
		        if(s1[i]==s2[j])
		            return true;
		    }
		}
		return false;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--) 
	{
		string a, b; cin >> a >> b;
		Solution ob;
		cout << ob.commonSubseq (a, b) << '\n';
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends