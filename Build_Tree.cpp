Node* buildTree(Node* root) // For creating normal Binary Tree
{
  int data;
  cin >> data;
  
  root = new Node(data);
  
  if(data == -1)
    return NULL;
  
  root->left = buildTree(root->left);
  root->right = buildTree(root->right);
  
  return root;
}

--------------------------------------------------------------------------------------------------------------------
  // Creating Binary Search Tree
  
 Node* buildBST(Node* root, int data)
{
  if(root == NULL){
    root = new Node(data);
    return root;
  }
  
  if(data > root->data)
    root->right = buildBST(root->right);
  else
    root->left = buildBST(root->left);
  
    return root;
}
  
 void takeInput(Node* root)
{
  int data;
  cin>>data;
  
  while(data != -1){
     root = buildBST(root, data);
     cin>>data;
   }
}
