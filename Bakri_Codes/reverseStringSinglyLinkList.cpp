#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* reverseLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
    return head;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

Node* createLinkedListFromString(string input) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (char c : input) {
        Node* newNode = new Node();
        newNode->data = c;
        newNode->next = nullptr;

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
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    Node* head = createLinkedListFromString(inputString);

    cout << "Input String: " << inputString << endl;

    head = reverseLinkedList(head);

    cout << "Reversed String: ";
    printLinkedList(head);

    return 0;
}
