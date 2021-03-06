
#include<bits/stdc++.h>
using namespace std;

int MaxSum(vector<vector<int>>&res,int n)
{
    int dp[n][n+2];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j]=res[i][j];
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j+1])+res[i][j];
        }
    }
    
    int sum=0;
    for(int i=0;i<=n;i++)
    {
        sum=max(sum,dp[n-1][i]);
    }
    return sum;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n;
    cin>>n;
    vector<vector<int>>res(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            res[i][j]=a;
            // cin>>res[i][j];
        }
    }
    cout<<MaxSum(res,n)<<endl;
    return 0;
}