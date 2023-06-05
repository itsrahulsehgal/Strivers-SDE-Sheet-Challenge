#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    queue<pair<BinaryTreeNode<int>*, int>> q;
        map<int, int>nodes;
        vector<int> ans;
        if(root == NULL)
        return ans;
        q.push({root, 0});
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            BinaryTreeNode<int>* node = top.first;
            int vertical = top.second;
            nodes[vertical] = node->data; 
            if(node -> left != NULL){
                q.push({node -> left , {vertical - 1 }});
            }
            if(node -> right != NULL){
                q.push({node -> right , {vertical + 1}});
            }
            
        }
        
        for(auto i: nodes)
        {
            ans.push_back(i.second);
        }
        return ans;
    
}
