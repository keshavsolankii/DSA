// Let root of tree 1 = r1 and root of tree 2 = r2.

bool identicalTrees(Node* r1, Node* r2)
{
  if(r1 == NULL && r2 == NULL)
    return true;
  if(r1 == NULL && r2 != NULL)
    return false;
  if(r1 != NULL && r2 == NULL)
    return false;
  
  bool left = identicalTrees(r1->left, r2->left);
  bool right = identicalTrees(r1->right, r2->right);
  
  bool ans = (r1->data == r2->data);
  
  if(left && right && ans)
    return true;
  else
    return false;
}
