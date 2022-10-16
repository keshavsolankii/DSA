void inOrder(Node* root, int &count)
{
  if(root == NULL)
    return;
  
  inOrder(root->left);
  
  if(root->left == NULL && root->right == NULL)
    count ++;
  
  inOrder(root->right);
}

int countLeafNode(Node* root)
{
  int count = 0;
  inOrder(root, count);
  return count;
}
