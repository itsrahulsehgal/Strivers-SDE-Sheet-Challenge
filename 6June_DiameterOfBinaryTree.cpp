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
int height(TreeNode<int>* node, int &diameter)
    {
        if(node == NULL)
        {
            return 0;
        }
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh+rh);
        return max(lh,rh) + 1;

    }
int diameterOfBinaryTree(TreeNode<int> *root)
{
        int diameter = 0;
        height(root, diameter);
        return diameter;
}
