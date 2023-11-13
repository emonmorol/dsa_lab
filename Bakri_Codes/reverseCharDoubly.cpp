#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

Node* reverseLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* temp = nullptr;
    Node* current = head;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }

    return head;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

Node* createLinkedListFromChars() {
    Node* head = nullptr;
    Node* tail = nullptr;
    char inputChar;

    cout << "Enter characters (type '.' to end input): " << endl;

    while (true) {
        cin >> inputChar;

        if (inputChar == '.') {
            break;
        }

        Node* newNode = new Node();
        newNode->data = inputChar;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

int main() {
    Node* head = createLinkedListFromChars();

    cout << "Input Characters: ";
    printLinkedList(head);

    head = reverseLinkedList(head);

    cout << "Reversed Characters: ";
    printLinkedList(head);

    return 0;
}
