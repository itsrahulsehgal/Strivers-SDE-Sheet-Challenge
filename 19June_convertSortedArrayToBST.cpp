#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
TreeNode<int>* solve(vector<int>& v, int l, int r){
  if(l>r){
    return NULL;
  }
  int mid = (l+r)/2;
  TreeNode<int>* root = new TreeNode<int>(v[mid]);
  root->left = solve(v, l, mid-1);
  root-> right = solve(v, mid+1,r);
  return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return solve(arr, 0, n-1);
}
