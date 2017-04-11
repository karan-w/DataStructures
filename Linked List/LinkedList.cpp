#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtTheHead(int x)
{
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = head;
    head = temp;
    cout << "Node inserted at " << temp << endl;
    cout << "Value inside the node " << temp ->data << endl;
}

void print()
{
    Node* temp = head;
    cout << "The list is : ";
    while (temp != NULL)
    {
        int data = temp -> data;
        cout << data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{

    return 0;
}
