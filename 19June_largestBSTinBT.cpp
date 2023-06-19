#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class NodeValue{
    public:
    int maxValue, minValue, maxSize;
    NodeValue(int minValue, int maxValue, int maxSize)
    {
        this->maxValue = maxValue;
        this->minValue = minValue;
        this->maxSize = maxSize;
    }
};
NodeValue largestBSThelper(TreeNode<int>* root)
{
    if(!root)
    return NodeValue(INT_MAX, INT_MIN, 0);
    auto left = largestBSThelper(root->left);
    auto right = largestBSThelper(root->right);
    if(left.maxValue < root->data && root->data < right.minValue)
    {
        //Yes, it's a BST
        return NodeValue(min(root->data, left.minValue), max(root->data, right.maxValue), 
        left.maxSize + right.maxSize + 1);
    }
    else
    {
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize , right.maxSize));
    }
}

int largestBST(TreeNode<int>* root) 
{
    return largestBSThelper(root).maxSize;
}
