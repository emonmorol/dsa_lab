#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct List {
    Node* head;

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

    void LL_insert_to_start(int newData) {
        Node* newNode = createNode(newData);

        if (head == NULL) {
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }

        head = newNode;
    }

    void LL_insert_after(int newData, int target) {
        Node* temp = head;
        while (temp->data != target) {
            temp = temp->next;
        }

        Node* newNode = createNode(newData);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void LL_insert_before(int newData, int target) {
        Node* temp = head;

        if (head == NULL) {
            LL_insert_to_start(newData);
            return;
        }

        while (temp->data != target) {
            temp = temp->next;
        }
       
        
             Node* newNode = createNode(newData);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    

       if (temp == head) {
            head = newNode;
        }
       
    }

    void LL_delete_node(int hasValue) {
        Node* temp = head;
        if (temp->data == hasValue) {
            if (temp->next == temp) {
                head = NULL;
            } else {
                head = temp->next;
                head->prev = temp->prev;
                temp->prev->next = head;
            }
            delete temp;
            return;
        }

        while (temp->data != hasValue) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* cursor = head;
        do {
            cout << cursor->data << " ";
            cursor = cursor->next;
        } while (cursor != head);
        
        cout << endl;;
         
    }
//     void printList() {
//     if (head == nullptr) {
//         cout << "List is empty" << endl;
//         return;
//     }

//     Node* cursor = head;
//     cout << "Forward: ";
//     do {
//         cout << cursor->data << " ";
//         cursor = cursor->next;
//     } while (cursor != head);

//     cout << endl << "Backward: ";
//     cursor = head->prev;  // Move to the last element
//     do {
//         cout << cursor->data << " ";
//         cursor = cursor->prev;
//     } while (cursor != head->prev);
//     cout << endl;
// }

};

int main() {
    List l;

    l.LL_insert_to_start(9);
    l.LL_insert_after(10, 9);
    l.LL_insert_before(13, 9);
     l.LL_insert_before(15, 9);
     l.LL_insert_before(17, 9);

    // l.LL_delete_node(9);

    l.printList();

    return 0;
}
