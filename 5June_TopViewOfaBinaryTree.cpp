#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root)
    {
        //Your code here
        queue<pair<TreeNode<int>*, int>> q;
        map<int, int>nodes;
        vector<int> ans;
        if(root == NULL)
        return ans;
        q.push({root, 0});
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            TreeNode<int>* node = top.first;
            int vertical = top.second;
            if(nodes.find(vertical) == nodes.end())
            nodes[vertical] = node->val; 
            if(node -> left != NULL){
                q.push({node -> left , {vertical - 1 }});
            }
            if(node -> right != NULL){
                q.push({node -> right , {vertical + 1}});
            }
            
        }

        for (auto i : nodes) {
          ans.push_back(i.second);
        }
        return ans;
    }
