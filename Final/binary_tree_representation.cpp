#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertRecursive() {
        int value;
        cin >> value;

        if (value == -1) {
            return nullptr;
        }

        Node* newNode = new Node(value);

        cout << "Enter left child for " << value << ": ";
        newNode->left = insertRecursive();

        cout << "Enter right child for " << value << ": ";
        newNode->right = insertRecursive();

        return newNode;
    }

   public:
    BST() {
        root = nullptr;
    }

    void createBinaryTree() {
        cout << "Enter root value (-1 for null): ";
        root = insertRecursive();
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }

    void postorderTraversal(Node* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout << root->data << " ";
        }
    }
    void postorderTraversal() {
        postorderTraversal(root);
        cout << endl;
    }


    void preorderTraversal(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }
    void preorderTraversal() {
        preorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    bst.createBinaryTree();
    
    // Printing inorder traversal of the BST
    cout << "Inorder Traversal of the BST: ";
    bst.inorderTraversal();
    cout << "Post Order Traversal of the BST: ";
    bst.postorderTraversal();
    cout << "Pre Order Traversal of the BST: ";
    bst.preorderTraversal();

    return 0;
}
