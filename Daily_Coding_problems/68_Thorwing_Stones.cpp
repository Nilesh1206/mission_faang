/*
This question is asked by Amazon. You are given a group of stones, all of which have a 
positive weight. At each turn, we select the heaviest two stones and smash them together. 
When smashing these two stones together, one of two things can happen:

If the stones are both the same weight, both stones are destroyed
If the weights of the stones are not equal, the smaller of the two stones is destroyed and 
the remaining stone’s weight is updated to the difference (i.e. if we smash two stones 
together of weight 3 and weight 5 the stone with weight 3 is destroyed and the stone with 
original weight 5 now has weight 2).
Continue smashing stones together until there is at most one stone left and return the
 weight of the remaining stone. If not stones remain, return zero.

Ex: Given the following stones…

stones = [2, 4, 3, 8], return 1
8 and 4 are smashed together, 4 is destroyed, 8 becomes 4.
4 and 3 are smashed together, 3 is destroyed, 4 becomes 1.
2 and 1 are smashed together, 1 is destroyed, 2 becomes 1.
1 is the last stone remaining and is therefore returned.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    priority_queue<int>pq(res.begin(),res.end());
    while(pq.size()!=1)
    {
        int top=pq.top();
        pq.pop();
        int secondTop=pq.top();
        pq.pop();
        pq.push(top-secondTop);
    }
    cout<<pq.top()<<endl;
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(n)