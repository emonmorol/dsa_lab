// #include <iostream>
// using namespace std;

// int linearSearch(int arr[], int size, int target) {
//     for (int i = 0; i < size; i++) {
//         if (arr[i] == target) {
//             return i; // Return index if the element is found
//         }
//     }
//     return -1; // Return -1 if the element is not found
// }

// int main() {
//     int size;
//     cout << "Enter the size of the array: ";
//     cin >> size;

//     int arr[size];
//     cout << "Enter " << size << " integers for the array: ";
//     for (int i = 0; i < size; i++) {
//         cin >> arr[i];
//     }

//     int target;
//     cout << "Enter the element to search for: ";
//     cin >> target;

//     int index = linearSearch(arr, size, target);

//     if (index != -1) {
//         cout << "Element found at index: " << index << endl;
//     } else {
//         cout << "Element not found in the array." << endl;
//     }

//     return 0;
// }

//char search linear

#include <iostream>
using namespace std;

int linearSearch(char arr[], int size, char target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if the character is found
        }
    }
    return -1; // Return -1 if the character is not found
}

int main() {
    int size;
    cout << "Enter the size of the character array: ";
    cin >> size;

    char arr[size];
    cout << "Enter " << size << " characters for the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    char target;
    cout << "Enter the character to search for: ";
    cin >> target;

    int index = linearSearch(arr, size, target);

    if (index != -1) {
        cout << "Character found at index: " << index << endl;
    } else {
        cout << "Character not found in the array." << endl;
    }

    return 0;
}
