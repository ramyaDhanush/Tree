// how to find that if two binary tree are same or different.

#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int data) : val{data}, left{nullptr}, right{nullptr} {}
};

bool isSameTree(TreeNode *root1, TreeNode *root2)
{
  if (root1 == NULL && root2 == NULL)
    return true;
  if (root1 == NULL || root2 == NULL)
    return false;

  return root1->val == root2->val && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

int main()
{
  TreeNode *root1 = new TreeNode(1);
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(3);
  TreeNode *left_left = new TreeNode(4);
  TreeNode *left_right = new TreeNode(5);
  TreeNode *right_left = new TreeNode(6);
  TreeNode *right_right = new TreeNode(7);

  root1->left = left;
  root1->right = right;

  left->left = left_left;
  left->right = left_right;

  right->left = right_left;
  right->right = right_right;

  TreeNode *root3 = root1;
  cout << isSameTree(root1, root3) << "\n";

  TreeNode *root2 = new TreeNode(1);
  TreeNode *left2 = new TreeNode(2);
  TreeNode *right2 = new TreeNode(3);
  TreeNode *left_left2 = new TreeNode(4);
  TreeNode *left_right2 = new TreeNode(5);
  TreeNode *right_left2 = new TreeNode(6);
  TreeNode *right_right2 = new TreeNode(75);

  root2->left = left2;
  root2->right = right2;

  left2->left = left_left2;
  left2->right = left_right2;

  right2->left = right_left2;
  right2->right = right_right2;
  cout << isSameTree(root1, root2) << "\n";
}
