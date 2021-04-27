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

int getSize(Node *root)
{
  if (root == nullptr)
    return 0;

  int leftSize = getSize(root->left);
  int rightSize = getSize(root->right);

  return leftSize + rightSize + 1;
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

  cout << getSize(root) << "\n";
  cout << getSize(right) << "\n";
  cout << getSize(right_left) << "\n";
}
