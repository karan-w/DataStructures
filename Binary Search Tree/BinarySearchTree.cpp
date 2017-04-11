#include <iostream>

using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* root = NULL;

void preOrder(BSTNode *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(BSTNode *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void inOrder(BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

}

int findSmallestBST(BSTNode *root)
{
    if(root->left == NULL)
    {
        return root->data;
    }
    else
        return findSmallestBST(root->left);

}
int findLargestBST(BSTNode* root)
{
    if(root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return findLargestBST(root);
    }
}

int lookFor(BSTNode* root, int number)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(number < root->data)
    {
        lookFor(root->left, number);
    }
    else if(number > root->data)
    {
        lookFor(root->right, number);
    }
    else if(number == root->data)
    {
        return 1;
    }

}
BSTNode* newNode(int number)
{
    BSTNode* newNode = new BSTNode();
    newNode->data = number;
    newNode->left = NULL;
    newNode->right = NULL;
}
BSTNode* insert(BSTNode* root, int number)
{
    if(root == NULL)
    {
        root = newNode(number);
    }
    else if(number < root->data)
    {
        root->left = insert(root->left, number);
    }
    else if(number > root->data)
    {
        root->right = insert(root->right, number);
    }

}
BSTNode* searchNode(BSTNode* root, int number)
{
    if(root->data == number || root == NULL)
    {
        return root;
    }
    else if(number < root->data)
    {
        searchNode(root->left, number);
    }
    else if(number > root->data)
    {
        searchNode(root->right, number);
    }



}
int findSuccessor(BSTNode* root, int number){
root = searchNode(root, number);
int successor = findSmallestBST(root->right);
return successor;
}
int main()
{
    BSTNode* root = new BSTNode();
    root->left = NULL;
    root->right = NULL;
    root->data = 5;
    int x = findSmallestBST(root);
    cout << x << endl;
    int found = lookFor(root, 4);
    cout << "Found :"<< found << endl;
    root = insert(root, 1);
    root = insert(root, 2);
    inOrder(root);
    int y = findLargestBST(root);
    cout << y << endl;
    int z = findSuccessor(root, 2);
    cout << z << endl;

    return 0;
}
