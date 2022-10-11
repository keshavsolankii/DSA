pair<bool, int> isSumTree(Node* root)
{
  if(root == NULL)
  {
    pair<bool, int> p = make_pair(NULL, 0);
    return p;
  }
  if(root -> left == NULL && root -> right == NULL)
  {
    pair<bool, int> p = make_pair(true, root->data);
    return p;
  }
  
  pair<bool, int> left = isSumTree(root->left);
  pair<bool, int> right = isSumTree(root->right);
  
  bool leftAns = left.first;
  bool.rightAns = right.first;
  
  bool val = (root->data == left.second + right.second);
  
  pair<bool, int> ans;
  
  if(leftAns && rightAns && val)
  {
    ans.first = true;
    ans.second = 2*root->data;
  }
  else
  {
    ans.first = false;
  }
  return ans;
}

// Time and space complexity is O(n)
