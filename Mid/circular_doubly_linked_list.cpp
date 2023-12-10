#include <iostream>

using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node* prev;
};

class List {
    Node* head;

   public:
    List() {
        head = NULL;
    }
    Node* createNode(int newData) {
        Node* temp = new Node();
        temp->data = newData;
        temp->prev = NULL;
        temp->next = NULL;
        return temp;
    }
    void LL_insert_to_beginning(int newData) {
        Node* newNode = createNode(newData);

        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
    }
    void LL_insert_at_end(int newData) {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Node* newNode = createNode(newData);
        newNode->prev = temp;
        temp->next = newNode;
    }

    void LL_insert_after(int newData, int target) {
        Node* temp = head;
        while (temp->next != NULL && temp->data != target) {
            temp = temp->next;
        }

        if (temp->next == NULL && target != temp->data) {
            LL_insert_at_end(newData);
            return;
        }
        Node* newNode = createNode(newData);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    void LL_insert_before(int newData, int target) {
        Node* temp = head;

        if (head == NULL || head->data == target) {
            LL_insert_to_beginning(newData);
            return;
        }

        while (temp->next != NULL && temp->data != target) {
            temp = temp->next;
        }
        if (temp->next == NULL && temp->data != target) {
            LL_insert_at_end(newData);
            return;
        }

        Node* newNode = createNode(newData);

        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void LL_delete_node(int hasValue) {
        Node* temp = head;
        if (temp->data == hasValue) {
            head = temp->next;
            head->prev = NULL;
            free(temp);
            return;
        }
        while (temp != NULL && temp->data != hasValue) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "The item doesn't exist \n";
            return;
        }
        if (temp->data == hasValue && temp->next == NULL) {
            temp->prev->next = NULL;
            free(temp);
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    void printList() {
        Node* Cursor;
        Cursor = head;
        while (Cursor) {
            cout << Cursor->data << " ";
            if (Cursor->next == NULL) break;
            Cursor = Cursor->next;
        }
        cout << endl;
        while (Cursor) {
            cout << Cursor->data << " ";
            Cursor = Cursor->prev;
        }
        cout << endl;
    }
};

int main() {
    List l;

    l.LL_insert_to_beginning(5);
    l.LL_insert_to_beginning(7);
    l.LL_insert_to_beginning(3);
    l.LL_insert_at_end(20);
    l.LL_insert_to_beginning(9);
    l.LL_insert_after(10, 3);
    l.LL_insert_before(13, 3);
    l.printList();

    l.LL_delete_node(3);
    l.printList();
    l.LL_delete_node(9);
    l.printList();
    l.LL_delete_node(20);
    l.printList();
    return 0;
}