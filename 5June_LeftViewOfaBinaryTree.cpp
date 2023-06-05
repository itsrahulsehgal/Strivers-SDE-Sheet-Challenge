#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int>* root, int level, vector<int> &ans)
    {
        if(root == NULL)
        return;
        if(ans.size() == level)
        ans.push_back(root->data);
        solve(root->left, level+1, ans);
        solve(root->right, level+1, ans);
    }
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
        solve(root, 0, ans);
        return ans;
}
