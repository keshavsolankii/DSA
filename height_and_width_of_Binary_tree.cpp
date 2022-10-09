#include <bits/stdc++.h>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node* &root)
{
    int data;
    cout << "Enter the data:" << endl;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of : " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of : " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int binaryHeight(Node* &root)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = binaryHeight(root->left);
    int right = binaryHeight(root->right);

    int ans = max(left, right)+1;
    
    return ans;
}

int widthOfBinaryTree(Node* root) { // Time complexity is O(n^2) because of double recursion as
        if(root == NULL)            // binaryHeight() is also having the T.C of O(n)
            return 0;
        
        int opt1 = widthOfBinaryTree(root->left);
        int opt2 = widthOfBinaryTree(root->right);
        int opt3 = binaryHeight(root->left) + binaryHeight(root->right) + 1;
        
        int ans = max(opt1, max(opt2,opt3));
        return ans;
    }

int main()
{
    Node *root = NULL;
    // Creating a tree

    root = buildTree(root); // 1 2 4 -1 5 -1 -1 -1 3 6 -1 -1 7 -1 -1

    cout<<"The height of the tree is "<<binaryHeight(root)<<endl;
    cout<<"The width of the tree is "<<widthOfBinaryTree(root);

    return 0;
}