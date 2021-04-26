// **Tree using LinkedList**

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int data) : data{data}, left{nullptr}, right{nullptr} {}
};

void print_dfs(Node *root)
{
  if (root == nullptr)
    return;

  cout << root->data << " ";
  print_dfs(root->left);
  print_dfs(root->right);
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
  print_dfs(root);
}