#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int data) : data{data}, left{nullptr}, right{nullptr} {}
};

int getMaxHeight(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }

  int leftHeight = getMaxHeight(root->left);
  int rightHeight = getMaxHeight(root->right);

  return max(leftHeight, rightHeight) + 1;
}

int main()
{
  Node *root = new Node(1);
  Node *left = new Node(2);
  Node *right = new Node(3);
  Node *left_left = new Node(4);
  Node *left_right = new Node(5);
  Node *right_left = new Node(6);
  Node *right_right = new Node(7);

  root->left = left;
  root->right = right;

  left->left = left_left;
  left->right = left_right;

  right->left = right_left;
  right->right = right_right;

  // Print DFS
  cout << getMaxHeight(root) << " ";
  cout << getMaxHeight(right_right) << " ";
  cout << getMaxHeight(right) << " ";
}
