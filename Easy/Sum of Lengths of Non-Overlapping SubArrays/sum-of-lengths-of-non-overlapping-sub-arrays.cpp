//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int calculateMaxSumLength(int arr[], int n, int k)
	{
		// Your code goes here
		vector<bool> vis(n, false);
		int res=0;
		for(int i=0;i<n;i++)
		{
		    if(arr[i]==k)
		    {
		        int l;
		        for(l=i-1;l>=0;l--)
		        {
		            if(vis[l] || arr[l]>=k)
		            {
		                break;
		            }
		            vis[l]=true;
		        }
		        int r;
		        for(r=i+1;r<n;r++)
		        {
		            if(vis[r] || arr[r]>=k)
		            {
		                break;
		            }
		            vis[r]=true;
		        }
		      //  cout<<l<<" "<<r<<endl;
		        int len=r-l-1;
		      //  cout<<len<<endl;
		        res+=len;
		    }
		}
		return res;
	}
		 

};

//{ Driver Code Starts.


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n, tmp;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	   	}
	   	cin>>tmp;
            
        
        

        Solution ob;
		cout << ob.calculateMaxSumLength(arr, n, tmp);
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends