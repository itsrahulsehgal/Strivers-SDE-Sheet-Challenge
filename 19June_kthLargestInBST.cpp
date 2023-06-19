//Method 1
/************************************************************
    Following is the Binary Search Tree node structure
    
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
void traverse(TreeNode<int>* root, vector<int> &inorder){
    if(root==NULL) return;
    traverse(root->left, inorder);
    inorder.push_back(root->data);
    traverse(root->right, inorder);
}


int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    vector<int> inorder;
    traverse(root, inorder);
    if(k>inorder.size()) return -1;
    return inorder[inorder.size()-k];
}
