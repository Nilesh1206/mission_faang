#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};



class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(!root)
        {
            return {};
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++)
            {
                Node* temp=q.front();
                q.pop();
                level.push_back(temp->val);
                //q.pop();
                for(auto it:temp->children)
                {
                    q.push(it);
                }
            }
            res.push_back(level);
            
        }
        return res;
    }
};
// Time Complexity:O(H)
// Space Complexity:O(n)