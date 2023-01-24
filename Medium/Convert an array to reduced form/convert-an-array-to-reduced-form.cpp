//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	int binser(int l, int h, int key, int arr[])
	{
	    int mid=l+(h-l)/2;
	    if(arr[mid]==key)
	        return mid;
	    if(arr[mid]>key)
	    {
	        return binser(l, mid-1, key, arr);
	    }
	    else
	    {
	        return binser(mid+1, h, key, arr);
	    }
	}
	void convert(int arr[], int n) {
	    // code here
	    int temp[n];
	    for(int i=0;i<n;i++)
	    {
	        temp[i]=arr[i];
	    }
	    sort(temp, temp+n);
	    for(int i=0;i<n;i++)
	    {
	        int j=binser(0, n, arr[i], temp);
	        arr[i]=j;
	    }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends