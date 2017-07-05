#include <iostream>
#include <cstdlib>

using namespace std;

template<typename dataType>
class Node {
public:
    dataType data;
    Node* left;
    Node* right;
    Node* parent;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    Node(const dataType &data) {
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

template<typename dataType>
class BST {
private:
    Node<dataType>* root;

    void inOrder(Node<dataType> *root) {
        if (root == NULL) {
            return;
        } else {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

    void postOrder(Node<dataType> *root) {
        if (root == NULL) {
            return;
        } else {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }
    }

    void preOrder(Node<dataType> *root) {
        if (root == NULL) {
            return;
        } else {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    dataType minimumRecursive(Node<dataType> *root) {
        if (root->left == NULL) {
            return root->data;
        } else {
            return minimumRecursive(root->left);
        }
    }

    dataType maximumRecursive(Node<dataType> *root) {
        if (root->right == NULL) {
            return root->data;
        } else {
            return maximumRecursive(root->right);
        }
    }

    bool search(Node<dataType> *traversingPointer, const dataType &number) {
        if (traversingPointer == NULL) {
            return 0;
        } else if (number == traversingPointer->data) {
            return 1;
        } else if (number < traversingPointer->data) {
            return search(traversingPointer->left, number);
        } else {
            return search(traversingPointer->right, number);
        }
    }

    Node<dataType> *searchNode(Node<dataType> *traversingPointer, const dataType &number) {
        if (traversingPointer == NULL) {
            return NULL;
        } else if (traversingPointer->data == number) {
            return traversingPointer;
        } else if (number < traversingPointer->data) {
            searchNode(traversingPointer->left, number);
        } else if (number >= traversingPointer->data) {
            searchNode(traversingPointer->right, number);
        }
    }
public:

    BST() {
        root = NULL;
    }

    Node<dataType>* getRoot() {
        return root;
    }

    void insert(const dataType &number) {
        Node<dataType>* parentNode = NULL;
        Node<dataType>* currentNode = root;
        Node<dataType>* newNode = new Node<dataType>(number);
        while (currentNode != NULL) {
            parentNode = currentNode;
            if (number < currentNode->data) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }
        newNode->parent = parentNode;
        //if the BST is empty
        if (parentNode == NULL) {
            root = newNode;
        } else if (number < parentNode->data) {
            parentNode->left = newNode;
        } else {
            parentNode->right = newNode;
        }
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    void postOrder() {
        postOrder(root);
        cout << endl;
    }

    void preOrder() {
        preOrder(root);
        cout << endl;
    }

    dataType minimumIterative() {
        Node<dataType> *traversingPointer = root;
        while (traversingPointer->left != NULL) {
            traversingPointer = traversingPointer->left;
        }
        return traversingPointer->data;
    }

    dataType maximumIterative() {
        Node<dataType> *traversingPointer = root;
        while (traversingPointer->right != NULL) {
            traversingPointer = traversingPointer->right;
        }
        return traversingPointer->data;
    }

    dataType minimumRecursive() {
        return minimumRecursive(root);
    }

    dataType maximumRecursive() {
        return maximumRecursive(root);
    }

    bool search(const dataType &number) {
        return search(root, number);
    }

    Node<dataType> *searchNode(const dataType &number) {
        return searchNode(root, number);
    }

    dataType successorOf(const dataType &number) {
        Node<dataType> *node = searchNode(root, number);
        dataType successor;
        if (node->right != NULL) {
            successor = minimumRecursive(node->right);
        } else {
            Node<dataType>* parent = node->parent;
            while ((parent != NULL) && (node == parent->right)) {
                node = parent;
                parent = parent->parent;
            }
            if (parent == NULL) {
                return -9999;
            }
            successor = parent->data;
        }
        return successor;
    }

    void transplant(Node<dataType>* node, Node<dataType>* child) {
        Node<dataType>* parent = node->parent;
        if (parent == NULL) {
            root = child;
        } else if (parent->right == node) {
            parent->right = child;

        } else if (parent->left == node) {
            parent->left = child;
        }
        if (child != NULL) {
            child->parent = node->parent;
        }
    }

    void deleteNode(const dataType &number) {
        Node<dataType>* node = searchNode(root, number);
        if (node == NULL) {
            cout << "Node doesn't exist." << endl;
            return;
        }
        if (node->left == NULL) {
            transplant(node, node->right);
        } else if (node->right == NULL) {
            transplant(node, node->left);
        } else {
            Node<dataType>* successor = searchNode(minimumRecursive(node->right));
            if(successor->parent != node){
                transplant(successor, successor->right);
                successor->right = node->right;
                (successor->right)->parent = successor;
            }
            transplant(node, successor);
            successor->left = node->left;
            (node->left)->parent = successor;
        }
        delete node;
    }
};

int main() 
    return 0;
}

