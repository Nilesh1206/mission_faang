/*
Problem Statement:
There are several projects, and each is denoted by a one letter name. Each project may 
depend on one or more other projects (or none). For example, if project A depends on 
project B, then project A cannot complete before project B. Suppose you are given a 
list L, of K such dependencies, and also a list D, of J projects that have been delayed. 
Output a list of all projects that will be delayed, in lexicographical (alphabetical) order.
 You can assume that a project, A, will be delayed if any project A depends on is delayed. 
 The input is guaranteed to contain no circular dependencies.

Input:

Test cases will be provided in the following multiline format. The first line contains 
one integer, C, which is the number of test cases that will follow. Each test case has 
the following format.

The first line of a test case contains two integers, K and J, separated by a space.
 K is the number of dependencies, and J is the number of delayed projects. 
 K lines follow, each with the format:

XY

where X and Y are the names of projects and project X depends on project Y, 
project names are single uppercase English letters. Each pair gives a project dependency:
 Y must complete before X can complete. All K lines together form the list L of 
 project dependencies.

Finally, the last line contains J space-delimited project names (single letters, uppercase). 
This gives the list D of length J of projects that have been delayed. Each project in D is
 listed in the dependency list at least once.

Limits:

Test case count: 1 <= C <= 20
Number of dependencies: 1 <= K <= 100
Number of projects: 1 <= J <= 26
Project name: Each name is a single uppercase letter from A to Z.
Outputs:
For each test case, output one line containing the test case index, starting from 1, 
followed by a space-delimited list of projects that will be delayed, do not add any
 space at the end of each line of output. The list must be in lexicographically sorted order.
  The resulting line should be in this format:

Case #i: X[1] X[2]...

where i is the index of the test case, starting from 1, and X[k] are the names of the
 projects that were delayed.

Sample Inputs:
3
2 1
B A
C B
B
5 2
P Q
P S
Q R
R T
S T
Q S
8 2
B A
C B
C E
D C
D F
E A
F E
G F
B F

Sample Output:
Case #1: B C
Case #2: P Q S
Case #3: B C D F G
*/

#include<bits/stdc++.h>
using namespace std;


void DFS(char src,unordered_map<char,vector<char>>&mp,unordered_map<char,bool>&visited,vector<char>&ans)
{
    if(visited[src]) return;
    ans.push_back(src);
    visited[src]=true;
    for(auto it:mp[src])
    {
        DFS(it,mp,visited,ans);
    }
}

int test=1;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        unordered_map<char,vector<char>>mp;
        for(int i=0;i<n;i++)
        {
            char u,v;
            cin>>u>>v;
            mp[v].push_back(u);
        }
        vector<char>list;
        while(q--)
        {
            char ch;
            cin>>ch;
            list.push_back(ch);
        }
        unordered_map<char,bool>visited;
        vector<char>ans;
        for(auto it:list)
        {
            if(!visited[it])
            {
                DFS(it,mp,visited,ans);
            }
        }
        sort(ans.begin(),ans.end());
        cout<<"Test: "<<test++<<endl;
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
// T:O(q*(n+26)+26log26)
// S:O(26)