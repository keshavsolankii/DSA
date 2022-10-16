// PreOrder traversal with iteration
void preOrder(Node* root)
{
  if(root == NULL)
    return ;
  stack<Node*> st;
  st.push(root);
  
  while(!st.empty())
  {
    Node* temp = st.top();
    st.pop();
    
    cout<<temp->data<<" ";
    
    if(temp -> left)
      st.push(temp->left);
    if(temp -> right)
      st.push(temp->right);
  }
}

// PostOrder traversal with iteration
void postOrder(Node* root)
{
  if(root == NULL)
    return;
  stack<Node*> st1, st2;
  st1.push(root);
  
  while(!st1.empty())
  {
    Node* temp = st1.top();
    st1.pop();
    
    st2.push(temp);
    
    if(temp -> right)
      st1.push(temp->right);
    if(temp -> left)
      st1.push(temp->left);
  }
  
  while(!st2.empty())
  {
    temp = st2.top();
    st2.pop();
    
    cout<<temp->data<<" "; 
  }
}

// InOrder Traversal using iteration

void inOrder(Node* root)
{
  stack<Node*> st;
  
  Node* temp = root;
  
  while(!st.empty() || temp != NULL)
  {
    while(temp != NULL)
    {
      st.push(temp);
      temp = temp -> left;
    }
    temp = st.top();
    st.pop();
    cout<<temp->data<<" ";
    
    temp = temp -> right;
  }
}
