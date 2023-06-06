#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    stack<pair<BinaryTreeNode<int>*, int>> st;
    vector<vector<int>> ans;
    if(root == NULL)
    return ans;
    st.push({root, 1});
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    while(!st.empty())
    {
        auto top = st.top();
        st.pop();

        if(top.second == 1)
        {
            preorder.push_back(top.first->data);
            top.second++;
            st.push(top);
            if(top.first->left!= NULL)
            st.push({top.first->left, 1});
        }
        else if(top.second == 2)
        {
            inorder.push_back(top.first->data);
            top.second++;
            st.push(top);
            if(top.first->right!= NULL)
            st.push({top.first->right, 1});
        }
        else
        {
            postorder.push_back(top.first->data);
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}
