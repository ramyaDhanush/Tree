# Tree
To hold basics and advanced concepts in tree data structure with problems that can be solved using tree
0. **FULL BINARY TREE / STRICTLY BINARY TREE**
   Every node must have two children, except the leaf nodes.
1. **INCOMPLETE BINARY TREE / ALMOST COMPLETE BINARY TREE**
   Every node must have two children's in all levels except second last level and should be filled from left to right.
2. **COMPLETE BINARY TREE / PERFECT BINARY TREE**
   Every node must have two children's in all the levels (Each level there should be 2^L where L is level)
3. **LEFT SKEWED BINARY TREE**
   Every node should have only left children.
4. **RIGHT SKEWED BINARY TREE**
   Every node should have only right children.

# LinkedList Representation
```cpp
// **Tree using LinkedList**

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int data): data{data}, left{nullptr}, right{nullptr}{}
};


void print_dfs(Node* root){
  if(root == nullptr) return;

  cout<<root->data<<" ";
  print_bfs(root->left);
  print_bfs(root->right);
}

int main(){
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
```

# Array Representation

If parent is p and array starts from 0 to n-1 then
   left child = (2*p)+1
   right child = (2*p)+2

Array starts from 1 to n then
   left child = (2*p)
   right child = (2*p)+1

```cpp
#include <iostream>
using namespace std;

char tree[10];

void root(char key){
  if(tree[1] != '\0'){
    cout<<"Tree Already have root";
  }
  else tree[1] = key;
}

void set_left(char key, int parent){
  if(tree[parent] == '\0'){
    cout<<"Can't set child at"<<(parent*2) + 1<<" , no parent found";
  }
  else tree[parent * 2] = key;
}

void set_right(char key, int parent){
  if(tree[parent] == '\0'){
    cout<<"Can't set child at"<<(parent*2) + 2<<" , no parent found";
  }
  else tree[(parent * 2) + 1] = key;
}

void print_tree(){
  for(int i=1; i<10; i++){
    if(tree[i] != '\0') cout<<tree[i]<<" ";
    else cout<<" null " ;
  }
}

int main(){
  root('A');
  set_left('B', 1);
  set_right('C', 1);
  set_left('D', 2);
  set_right('E', 2);
  set_left('F', 3);
  set_right('G', 3);
  print_tree();
}
```

# Height of a binary tree