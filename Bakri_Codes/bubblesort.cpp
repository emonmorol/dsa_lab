// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter the number of elements: ";
//     cout << "Enter the number of elements: ";
//     cin >> n;

//     int arr[n];
//     cout << "Enter " << n << " integers: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     bool isSorted;  // Flag to check if the array is already sorted

//     for (int i = 0; i < n - 1; i++) {
//         isSorted = true;  // Assume the array is sorted at the beginning of each pass
//         for (int j = 0; j < n - i - 1; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 swap(arr[j], arr[j + 1]);
//                 isSorted = false;  // If a swap occurs, the array is not sorted
//             }
//         }

//         // If the inner loop completes without any swaps, the array is already sorted
//         if (isSorted) {
//             break;
//         }
//     }

//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

//using linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int newData) {
        Node* newNode = new Node(newData);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void bubbleSort() {
        if (head == nullptr || head->next == nullptr) {
            return; // Already sorted or empty list
        }

        bool isSorted;
        do {
            isSorted = true;
            Node* current = head;
            Node* prev = nullptr;
            Node* nextNode = nullptr;

            while (current != nullptr && current->next != nullptr) {
                nextNode = current->next;

                if (current->data > nextNode->data) {
                    if (prev != nullptr) {
                        prev->next = nextNode;
                    } else {
                        head = nextNode;
                    }

                    current->next = nextNode->next;
                    nextNode->next = current;
                    prev = nextNode;

                    isSorted = false;
                } else {
                    prev = current;
                    current = current->next;
                }
            }
        } while (!isSorted);
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    LinkedList list;
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.append(num);
    }

    list.bubbleSort();

    cout << "Sorted array: ";
    list.display();

    return 0;
}
