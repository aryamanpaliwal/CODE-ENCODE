//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG{
    public static void main(String args[]) throws IOException{
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int n=sc.nextInt();
            int d=sc.nextInt();
            
            int []arr=new int[n];
            for(int i=0;i<n;i++){
                arr[i]=sc.nextInt();
            }
            
            Solution obj=new Solution();
            int res=obj.countPartitions(n, d, arr);
            System.out.println(res);
        }
    }
}
// } Driver Code Ends


//User function Template for Java

//Back-end complete function Template for Java

class Solution{

    public int countPartitions(int n, int d, int arr[]){
        // Code here
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if((sum+d)%2==1 || sum<d || n==1)
            return 0;
        sum=(sum+d)/2;
        int dp[][] = new int[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j>=arr[i-1])
                    dp[i][j]=(dp[i-1][j] + dp[i-1][j-arr[i-1]])%1000000007;
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
}