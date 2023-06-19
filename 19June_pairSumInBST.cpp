//METHOD 1
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void inorder(vector<int> &v,BinaryTreeNode<int>* root){
    if(root==NULL) return;
    inorder(v,root->left);
    v.push_back(root->data);
    inorder(v, root->right);
}


bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> v;
    inorder(v, root);
    int i=0, j=v.size()-1;
    while(i<j){
        if(v[i]+v[j]==k) return true;
        else if(v[i]+v[j]>k) j--;
        else i++;
    }
    return false;

}
