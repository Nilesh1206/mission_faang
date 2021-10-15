// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


class Solution 
{
    static bool myCmp(Job arr1,Job arr2)
    {
        return arr1.profit>arr2.profit;
    }
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,myCmp);
        bool done[n]={0};
        int day=0;
        int profit=0;
        for(int i=0;i<n;i++)
        {
            for(int j=min(n,arr[i].dead-1);j>=0;j--)
            {
                if(done[j]==false)
                {
                    day+=1;
                    profit+=arr[i].profit;
                    done[j]=true;
                    break;
                }
            }
        }
        vector<int>v;
        v.push_back(day);
        v.push_back(profit);
        return v;
    } 
};
 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}