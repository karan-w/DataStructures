#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createANode(int x) {
    Node* temp = new Node();
    temp->data = x;
    return temp;
}

class LinkedList {
private:
    Node *head;
    int size;

public:

    LinkedList() {
        head = NULL;
        size = 0;
    }

    void insertAtTheHead(int x) {
        Node* newNode = createANode(x);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void deleteAtTheHead() {
        Node *node = head;
        head = head -> next;
        delete node;
        size--;
    }

    void deleteAtTheTail() {
        Node* currentNode = head;
        Node* prevNode = head;
        if (currentNode == NULL) {
            return;
        }
        currentNode = currentNode -> next;
        if (currentNode == NULL) {
            head = NULL;
        } else {
            while (currentNode -> next != NULL) {
                prevNode = currentNode;
                currentNode = currentNode -> next;
            }
            prevNode -> next = NULL;
        }
        delete currentNode;
        size--;
    }

    void print() {
        Node* traversingPointer = head;
        cout << "The list is : ";
        int data = 0;
        while (traversingPointer != NULL) {
            data = traversingPointer -> data;
            cout << data << " ";
            traversingPointer = traversingPointer -> next;
        }
        cout << endl;
    }

    bool search(int x) {
        Node* traversingPointer = head;
        bool flag = 0;
        while (traversingPointer != NULL) {
            if (traversingPointer->data == x) {
                flag = 1;
                break;
            }
            traversingPointer = traversingPointer -> next;
        }
        return (flag == 1);
    }

    void insertAtTheTail(int x) {
        Node* traversingPointer = head;
        Node* newNode = createANode(x);
        if (traversingPointer == NULL) {
            insertAtTheHead(x);
        }
        while (traversingPointer -> next != NULL) {
            traversingPointer = traversingPointer -> next;
        }
        traversingPointer -> next = newNode;
        size++;
    }

    int elementAt(int position) {
        int count = 1;
        Node* traversingPointer = head;
        while (position != count) {
            traversingPointer = traversingPointer -> next;
            count++;
        }
        int data = traversingPointer -> data;
        cout << "Element at " << position << " : " << data << endl;
    }

    void insertAt(int position, int x) {
        Node* newNode = createANode(x);
        Node* traversingPointer = head;
        int count = 2;
        if (position == 1) {
            insertAtTheHead(x);
        } else {
            while (count < position) {
                traversingPointer = traversingPointer -> next;
                count++;
            }
            newNode -> next = traversingPointer -> next;
            traversingPointer -> next = newNode;
        }
        size++;
    }

    void deleteAt(int position) {
        Node* traversingPointer = head;
        if (position == 1) {
            head = traversingPointer -> next;
            delete traversingPointer;
        } else {
            int count = 2;
            while (count < position) {
                traversingPointer = traversingPointer -> next;
                count++;
            }
            Node* node = traversingPointer -> next;
            traversingPointer -> next = node -> next;
            delete node;
        }
        size--;
    }

    void reversePrint(Node* head) {
        if (head == NULL) {
            return;
        }
        reversePrint(head->next);
        cout << head->data << endl;
    }
    void reverseLinkedList(){
        Node* previousNode = head;
        Node* currentNode = head;
        Node* nextNode = head;
        if(head == NULL){
            return;
        }
        if(currentNode -> next == NULL){
            return;
        }
        currentNode = currentNode -> next;
        nextNode = currentNode -> next;
        if(nextNode == NULL){
            currentNode -> next = previousNode;
            head = currentNode;
            previousNode -> next = NULL;
            return;
        }
       
        while(currentNode != NULL){
            currentNode -> next = previousNode;
            previousNode =  currentNode;
            currentNode = nextNode;
            if(nextNode == NULL){
            break;
            }
            nextNode = nextNode -> next; 
        }
        head = previousNode;

    }
    int getSize() {
        return size;
    }

    Node* getHead() {
        return head;
    }
};

int main() {

    return 0;
}
