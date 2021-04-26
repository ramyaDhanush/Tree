#include <iostream>
using namespace std;

char tree[10];

void root(char key)
{
  if (tree[1] != '\0')
  {
    cout << "Tree Already have root";
  }
  else
    tree[1] = key;
}

void set_left(char key, int parent)
{
  if (tree[parent] == '\0')
  {
    cout << "Can't set child at" << (parent * 2) + 1 << " , no parent found";
  }
  else
    tree[parent * 2] = key;
}

void set_right(char key, int parent)
{
  if (tree[parent] == '\0')
  {
    cout << "Can't set child at" << (parent * 2) + 2 << " , no parent found";
  }
  else
    tree[(parent * 2) + 1] = key;
}

void print_tree()
{
  for (int i = 1; i < 10; i++)
  {
    if (tree[i] != '\0')
      cout << tree[i] << " ";
    else
      cout << " null ";
  }
}

int main()
{
  root('A');
  set_left('B', 1);
  set_right('C', 1);
  set_left('D', 2);
  set_right('E', 2);
  set_left('F', 3);
  set_right('G', 3);
  print_tree();
}