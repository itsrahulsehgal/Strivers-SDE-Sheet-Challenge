/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return root;
    if(root->left==NULL) {
        root->right= flattenBinaryTree(root->right);
        return root;
    }
    if(root->right==NULL) {
        root->right=flattenBinaryTree(root->left);
        return root;
    }
    TreeNode<int> *left= flattenBinaryTree(root->left);
    TreeNode<int> *right= flattenBinaryTree(root->right);
    
    root->right=left;
    while(left->right!=NULL){
        left=left->right;
    }
    left->right=right;
    return root;
}

