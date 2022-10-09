// There is a Node class, having int data, Node* left, Node* right
// Code for determining whether the Binary Tree is balanced or not

int height(Node* root)
{
  if(root == NULL)
    return 0;
  
  int left = height(root->left);
  int right = height(root->right);
  
  int ans = max(left, right) + 1; // 1 is added so that root node is also included
  return ans;
}

bool isBalanced(Node* root)
{
  if(root == NULL)
    return true; // If it is a leaf node, so it will be balanced
  
  int left = isBalanced(root->left);
  int right = isBalanced(root->right);
  
  // Now we have to subtract the height of the left and the right sub trees in order to determine whether the tree is balanced or not
  bool diff = abs(height(root->left) - height(root->right)) <= 1;
  return diff;
}
