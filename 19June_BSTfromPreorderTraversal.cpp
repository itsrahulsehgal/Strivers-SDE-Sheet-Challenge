
#include<bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* create(vector<int>&preOrder, int &i, int max){
    if(i==preOrder.size() || preOrder[i] > max) 
    return NULL;
    
    TreeNode<int>* root= new TreeNode<int>(preOrder[i]);
    i++;
    root->left= create(preOrder, i, root->data);
    root->right= create(preOrder, i, max);
    return root;
}


TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i=0;
    return create(preOrder, i, INT_MAX);
}
