// Pure DP of Longest common subsequence
#include<bits/stdc++.h>
using namespace std;

int LCS(string X,string Y,int m,int n)
{
    int dp[m+1][n+1]; // Initialazation of array to store the values
    for(int i=0;i<=m;i++) //Filling first row and column as zero
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            //IF both char matched of both the string , then add 1 to the upper left cross
            // block of that matrix and update it in current block
            if(X[i-1]==Y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            // If character of respective row nad column doesn't match
            // i.e row-1 > column-1 then ...iterate column one block behind i.e. j--
            // ultimately row number will remains same ..in this case we have to take the maximum of this two
            // blocks and update value in the current block.
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ind=dp[m][n];
    int i=m;
    int j=n;
    string str(ind+1,'\0');
    while(i>0 && j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            str[ind-1]=X[i-1];
            i--;
            j--;
            ind--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout<<endl;
    cout<<str<<endl;
    cout<<endl;
    return dp[m][n];
}
// Time Complexity :O(n*n)
// Space Complexity :O(n*n)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string X="binarysearch"; 
    // Just think about second string , it is not gien ....
    // Reminder the example of LCS , there we have given two strings ...so that we can easily find the LCS
    // But here we have given only one string ....so for second string , we have to just reverse the 
    // first the string and apply LCS on it
    // DP of top down-approach 
    string Y=string(X.rbegin(),X.rend());
    int m=X.length();
    int n=Y.length();
    cout<<"Length of Longest Palindromic Subsequence is: "<<LCS(X,Y,m,n)<<"\n";
    return 0;
}