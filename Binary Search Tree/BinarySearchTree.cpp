#include <iostream>

using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
    };

BSTNode* root = NULL;

void preOrder(BSTNode *root){
    if(root == NULL){
       return;
    }
    else{
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(BSTNode *root) {
    if(root == NULL){
        return;
    }
    else{
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void inOrder(BSTNode *root){
    if (root == NULL){
        return;
    }
    else{
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

}
int main()
{


    return 0;
}
