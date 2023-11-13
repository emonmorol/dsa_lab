#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
    return head;
}

void printLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->data << ">";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n, value;
    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of nodes: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    cout << "Input Linked List: ";
    printLinkedList(head);

    head = reverseLinkedList(head);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
